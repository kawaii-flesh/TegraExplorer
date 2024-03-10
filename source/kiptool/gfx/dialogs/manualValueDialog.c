#include "manualValueDialog.h"

#include <string.h>
#include <utils/util.h>

#include "../../../gfx/gfxutils.h"
#include "../../../hid/hid.h"
#include "../../params/param.h"
#include "../gfx.h"
#include "confirmationDialog.h"

unsigned int numPlaces(unsigned int n) {
    unsigned int r = 1;
    while (n > 9) {
        n /= 10;
        r++;
    }
    return r;
}

bool validateValue(unsigned int min, unsigned int max, unsigned int stepSize, const unsigned int value) {
    return min <= value && value <= max && value % stepSize == 0;
}

ManualValueResult manualValueDialog(const Param* param, int defaultValue) {
    const FixedLimits* fixedLimits = NULL;
    for (unsigned int i = 0; i < param->limitsCount; ++i)
        if (param->limits[i].type == EFixedLimits) fixedLimits = param->limits[i].values;
    if (fixedLimits == NULL) {
        const ManualValueResult notFixedLimits = {.status = EMVS_ITS_NOT_FIXEDLIMITS};
        return notFixedLimits;
    }

    int min = fixedLimits->min;
    int max = fixedLimits->max;
    int stepSize = fixedLimits->stepSize;
    int currentValue = defaultValue;
    if (currentValue == -1) {
        currentValue = min + (max - min) / 2;
        if (currentValue % stepSize != 0) currentValue += currentValue % stepSize;
    }
    unsigned int holdTimer = 200;
    const unsigned int linesCount = 5;
    const char help[] = "dec(<) inc(>) apply(A) back(B)";
    const char* measure = param->measure != NULL ? param->measure : fixedLimits->measure != NULL ? fixedLimits->measure : "";
    const unsigned int minMaxDif = numPlaces(max) - numPlaces(min);
    unsigned int maxStringLen = 18 + numPlaces(min > 1500 ? min / 1000 : min) + numPlaces(max > 1500 ? max / 1000 : max) * 2 +
                                numPlaces(stepSize > 1500 ? stepSize / 1000 : stepSize) +
                                (measure != NULL ? strlen(measure) : 0) + minMaxDif + 6;
    unsigned int fontSize = gfx_con.fntsz;
    unsigned int boxWidth = (maxStringLen * fontSize) + fontSize * 2;
    unsigned int boxHeight = (linesCount * fontSize) + fontSize * 2;
    unsigned int boxX0Position = 1280 / 2 - boxWidth / 2;
    unsigned int boxX1Position = 1280 / 2 + boxWidth / 2;
    unsigned int boxY0Position = 720 / 2 - boxHeight / 2;
    unsigned int boxY1Position = 720 / 2 + boxHeight / 2;
    unsigned int boxXMid = boxX0Position + boxWidth / 2;
    unsigned int paramNameXPosition = boxXMid - (strlen(param->name) / 2) * fontSize;
    unsigned int helpXPosition = boxXMid - 15 * fontSize;

    unsigned int paramNameYPosition = boxY0Position + 1 * fontSize;
    unsigned int helpYPosition = boxY0Position + 3 * fontSize;
    unsigned int selectorY0Position = boxY0Position + 5 * fontSize;

    unsigned int lastPress = 1000 + get_tmr_ms();
    unsigned int lastResult = currentValue;
    const int mult = 10;
    bool redraw = true;
    bool fullRedraw = true;
    Input_t* input = hidRead();
    Input_t oldButtons = *input;

    while (1) {
        if (redraw) {
            gfx_printTopInfoKT();
            SETCOLOR(COLOR_WHITE, COLOR_GREY);
            if (fullRedraw) {
                minerva_periodic_training();
                gfx_box(boxX0Position, boxY0Position, boxX1Position, boxY1Position, COLOR_GREY);
                gfx_con_setpos(paramNameXPosition, paramNameYPosition);
                gfx_puts(param->name);
                gfx_con_setpos(helpXPosition, helpYPosition);
                gfx_puts(help);
                fullRedraw = false;
            }
            redraw = false;
            char* minStr = malloc(8);
            formatValue(minStr, min);
            char* currentStr = malloc(8);
            formatValue(currentStr, currentValue);
            char* maxStr = malloc(8);
            formatValue(maxStr, max);
            char* stepStr = malloc(8);
            formatValue(stepStr, stepSize);
            char* buff = calloc(256, 1);
            s_printf(buff, "min=>%s %s %s<=max step=%s%s", minStr, currentStr, maxStr, stepStr, measure);
            maxStringLen = strlen(buff);
            unsigned int selectorX0Position = boxXMid - (maxStringLen / 2) * fontSize;
            gfx_box(boxX0Position, selectorY0Position, boxX1Position, selectorY0Position + fontSize, COLOR_GREY);
            gfx_con_setpos(selectorX0Position, selectorY0Position);
            gfx_printf("min=>%s %k%s%k %s<=max step=%s%s", minStr, COLOR_ORANGE, currentStr, COLOR_WHITE, maxStr, stepStr,
                       measure);
            free(minStr);
            free(currentStr);
            free(maxStr);
            free(stepStr);
            free(buff);
        }
        while (!hidRead()->buttons || oldButtons.buttons == input->buttons) {
            if ((lastPress + holdTimer) < get_tmr_ms() && oldButtons.buttons == input->buttons)
                break;
            else if (oldButtons.buttons != input->buttons)
                oldButtons = *input;
        }
        while (1) {
            if (input->buttons) oldButtons = *input;
            if (oldButtons.a) {
                if (validateValue(min, max, stepSize, currentValue)) {
                    const ManualValueResult good = {.value = currentValue, .status = EMVS_GOOD};
                    if (confirmationDialog("Set new value?", EYES) == EYES)
                        return good;
                    else {
                        oldButtons = *hidRead();
                        fullRedraw = true;
                        redraw = true;
                        break;
                    }
                } else {
                    const ManualValueResult invalidValue = {.status = EMVS_INVALID_VALUE};
                    return invalidValue;
                }
            } else if (oldButtons.b) {
                const ManualValueResult exit = {.status = EMVS_EXIT};
                if (confirmationDialog("Close?", EYES) == EYES)
                    return exit;
                else {
                    oldButtons = *hidRead();
                    fullRedraw = true;
                    redraw = true;
                    break;
                }
                return exit;
            } else if (!(hidRead()->buttons))
                break;
            else if ((lastPress + holdTimer) < get_tmr_ms())
                break;
        }

        if (oldButtons.right) {
            if (currentValue + stepSize < max)
                currentValue += stepSize;
            else
                currentValue = max;
        } else if (oldButtons.left) {
            if (min < currentValue - stepSize)
                currentValue -= stepSize;
            else
                currentValue = min;
        } else if (oldButtons.up) {
            if (currentValue + stepSize * mult < max)
                currentValue += stepSize * mult;
            else
                currentValue = max;
        } else if (oldButtons.down) {
            if (min < currentValue - stepSize * mult)
                currentValue -= stepSize * mult;
            else
                currentValue = min;
        }
        if (currentValue != lastResult) {
            if (currentValue % stepSize != 0) currentValue += currentValue % stepSize;  // TODO adjust, wrong stepsize?
            lastResult = currentValue;
            redraw = true;
        }
        lastPress = get_tmr_ms();
    }
}