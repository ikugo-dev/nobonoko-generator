#include "image_displayer.h"
#include "simple_include.h"

GuiWindowFileDialogState fileDialogState =
                        InitGuiWindowFileDialog(GetWorkingDirectory());

void FileSelect(Image &image, char fileNameToLoad[512]) {
    fileDialogState.supportDrag = false; //we can add this later
    fileDialogState.windowBounds = (Rectangle){ 100, 100, 500, 500 };

/* --------------------------------- update --------------------------------- */
    if (fileDialogState.SelectFilePressed)
    {
        // Load image file (if supported extension)
        if (IsFileExtension(fileDialogState.fileNameText, ".png"))
        {
            strcpy(fileNameToLoad,
                   TextFormat("%s/%s",
                               fileDialogState.dirPathText,
                               fileDialogState.fileNameText));
            image = LoadImage(fileNameToLoad);
            ImageResize(&image, 500, 500);

            ImageDisplayer::Update(image);
        }

        fileDialogState.SelectFilePressed = false;
    }
/* -------------------------------------------------------------------------- */
/* ---------------------------------- draw ---------------------------------- */

/* -------------------------------------------------------------------------- */
    if (fileDialogState.windowActive)
        GuiLock();
    if (GuiButton((Rectangle){ 20, 20, 140, 30 },
        GuiIconText(ICON_FILE_OPEN, "Open Image")))
    DrawText(fileNameToLoad, 20, 60, 10, GRAY);

        fileDialogState.windowActive = true;
    GuiUnlock();
/* -------------------------------------------------------------------------- */
    GuiWindowFileDialog(&fileDialogState);
/* -------------------------------------------------------------------------- */
}