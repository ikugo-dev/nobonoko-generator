#include "raylib.h"
#include "image_displayer.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#undef RAYGUI_IMPLEMENTATION            // Avoid including raygui implementation again
#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "gui_window_file_dialog.h"

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
        fileDialogState.windowActive = true;

    DrawText(fileNameToLoad, 20, 60, 10, GRAY);

    GuiUnlock();
/* -------------------------------------------------------------------------- */
    GuiWindowFileDialog(&fileDialogState);
/* -------------------------------------------------------------------------- */
}