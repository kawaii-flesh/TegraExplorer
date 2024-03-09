#include "tableMenu.h"

#include "editorMenu.h"
#include "ktMenu.h"
#include "paramsMenu.h"
#include <mem/heap.h>

void newTableMenu(const u8* custTable, const Table* table) {
    const unsigned int paramsCount = table->paramsCount;
    unsigned int totalEntriesCount = 1 + table->paramsCount;
    MenuEntry* menuEntries = calloc(sizeof(MenuEntry), totalEntriesCount);
    menuEntries[0].optionUnion = COLORTORGB(COLOR_WHITE) | SKIPBIT;
    menuEntries[0].type = ELabel;
    menuEntries[0].entry = table->name;
    unsigned int menuEntriesIndex = 1;
    for (unsigned int paramI = 0; paramI < paramsCount; ++paramI) {
        menuEntries[menuEntriesIndex].optionUnion = COLORTORGB(COLOR_VIOLET);
        menuEntries[menuEntriesIndex].type = EParam;
        menuEntries[menuEntriesIndex].entry = table->params[paramI];
        ++menuEntriesIndex;
    }
    int res = newMenuKT(menuEntries, totalEntriesCount, 0, custTable, printParamEntry);
    if (res == -1) {
        free(menuEntries);
        return;
    }
    const MenuEntry selectedEntry = menuEntries[res + 1];
    free(menuEntries);
    newEditorMenu(custTable, selectedEntry.entry);
    return;
}