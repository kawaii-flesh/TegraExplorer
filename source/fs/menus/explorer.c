#include "explorer.h"

#include <libs/fatfs/ff.h>
#include <mem/heap.h>
#include <string.h>

#include "../../err.h"
#include "../../gfx/gfx.h"
#include "../../gfx/gfxutils.h"
#include "../../gfx/menu.h"
#include "../../hid/hid.h"
#include "../../kiptool/gfx/dialogs/confirmationDialog.h"
#include "../../tegraexplorer/tconf.h"
#include "../../utils/utils.h"
#include "../../utils/vector.h"
#include "../fscopy.h"
#include "../fsutils.h"
#include "../readers/folderReader.h"
#include "filemenu.h"
#include "foldermenu.h"

#define SD_ROOT "sd:/"

MenuEntry_t topEntries[] = {{.optionUnion = COLORTORGB(COLOR_GREEN) | SKIPBIT},
                            {.optionUnion = COLORTORGB(COLOR_ORANGE)},
                            {.optionUnion = COLORTORGB(COLOR_GREY) | SKIPBIT, .name = "Clipboard -> Current folder"},
                            {.optionUnion = COLORTORGB(COLOR_ORANGE), .name = "Current folder options"}};

MenuEntry_t MakeMenuOutFSEntry(FSEntry_t entry) {
    MenuEntry_t out = {.name = entry.name, .sizeUnion = entry.sizeUnion};
    out.optionUnion = (entry.isDir) ? COLORTORGB(COLOR_WHITE) : COLORTORGB(COLOR_VIOLET);
    out.icon = (entry.isDir) ? 127 : 128;

    return out;
}

void FileExplorer(const char* path) {
    char* storedPath = CpyStr(path);
    int res = 0;

    if (TConf.explorerCopyMode == CMODE_Move || TConf.explorerCopyMode == CMODE_MoveFolder) ResetCopyParams();

    while (1) {
        topEntries[2].optionUnion = (TConf.explorerCopyMode != CMODE_None) ? (COLORTORGB(COLOR_ORANGE)) : (COLORTORGB(COLOR_GREY) | SKIPBIT);
        topEntries[1].name = (!strcmp(SD_ROOT, storedPath)) ? "<- Exit explorer" : "<- Folder back";

        gfx_clearscreen();
        gfx_printf("Loading...\r");

        int readRes = 0;
        Vector_t fileVec = ReadFolder(storedPath, &readRes);
        if (readRes) {
            clearFileVector(&fileVec);
            DrawError(newErrCode(readRes));
            return;
        }

        vecDefArray(FSEntry_t*, fsEntries, fileVec);

        topEntries[0].name = storedPath;
        Vector_t entries = newVec(sizeof(MenuEntry_t), fileVec.count + ARR_LEN(topEntries));
        entries.count = ARR_LEN(topEntries);
        memcpy(entries.data, topEntries, sizeof(MenuEntry_t) * ARR_LEN(topEntries));

        for (int i = 0; i < fileVec.count; i++) {
            MenuEntry_t a = MakeMenuOutFSEntry(fsEntries[i]);
            vecAddElem(&entries, a);
        }

        gfx_con_setpos(144, 24);
        gfx_boxGrey(0, 16, 160, 31, 0x1B);

        if (res >= fileVec.count + ARR_LEN(topEntries)) res = 0;

        res = newMenu(&entries, res, 60, 42, ENABLEB | ENABLEPAGECOUNT, (int)fileVec.count);
        vecFree(entries);

        char* oldPath = storedPath;

        if (res == 2) {
            ErrCode_t err = {0};
            char* filename = CpyStr(strrchr(TConf.srcCopy, '/') + 1);
            char* dst = CombinePaths(storedPath, filename);

            if (!strcmp(TConf.srcCopy, dst)) err = newErrCode(TE_ERR_SAME_LOC);

            if (!err.err && TConf.explorerCopyMode >= CMODE_CopyFolder) {
                if (strstr(dst, TConf.srcCopy) != NULL) err = newErrCode(TE_ERR_PATH_IN_PATH);
            }

            if (!err.err) {
                if (TConf.explorerCopyMode == CMODE_Move || TConf.explorerCopyMode == CMODE_MoveFolder) {
                    if ((err.err = f_rename(TConf.srcCopy, dst))) err = newErrCode(err.err);
                } else if (TConf.explorerCopyMode == CMODE_Copy) {
                    if (FileExists(dst)) {
                        const char* fileMessage[] = {"The file already exists.", "Do you want to overwrite it?", NULL};
                        if (confirmationDialog(fileMessage, ENO) != EYES) continue;
                    }
                    gfx_clearscreen();
                    RESETCOLOR;
                    gfx_printf("Hold vol+/- to cancel\nCopying %s... ", filename);
                    err = FileCopy(TConf.srcCopy, dst, COPY_MODE_CANCEL | COPY_MODE_PRINT);
                } else {
                    if (DirExists(dst)) {
                        const char* dirMessage[] = {"The dir already exists.", "Do you want to overwrite it?", NULL};
                        if (confirmationDialog(dirMessage, ENO) != EYES) continue;
                    }
                    gfx_clearscreen();
                    RESETCOLOR;
                    gfx_printf("\nCopying folder... ");
                    err = FolderCopy(TConf.srcCopy, storedPath);
                }
            }

            DrawError(err);
            free(dst);
            free(filename);
            ResetCopyParams();
        } else if (res == 3) {
            if (FolderMenu(storedPath)) {
                storedPath = EscapeFolder(oldPath);
                free(oldPath);
                res = 0;
            }
        } else if (res < ARR_LEN(topEntries) || res == -1) {
            if (!strcmp(SD_ROOT, storedPath)) {
                clearFileVector(&fileVec);
                free(storedPath);
                return;
            }
            storedPath = EscapeFolder(oldPath);
            free(oldPath);
            res = 0;
        } else if (fsEntries[res - ARR_LEN(topEntries)].isDir) {
            storedPath = CombinePaths(storedPath, fsEntries[res - ARR_LEN(topEntries)].name);
            free(oldPath);
            res = 0;
        } else {
            FileMenu(storedPath, fsEntries[res - ARR_LEN(topEntries)]);
        }

        clearFileVector(&fileVec);
    }
}
