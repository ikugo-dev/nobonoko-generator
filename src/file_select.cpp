#include "../lib/program_specs.h"
#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "../lib/raygui.h"

#undef RAYGUI_IMPLEMENTATION            // Avoid including raygui implementation again
#define GUI_WINDOW_FILE_DIALOG_IMPLEMENTATION
#include "../lib/gui_window_file_dialog.h"

GuiWindowFileDialogState fileDialogState =
                        InitGuiWindowFileDialog(GetWorkingDirectory());


static Image originalImage;
static Texture2D originalTexture;
Texture2D GetOriginalTexture() {
    return originalTexture;
}

Image FileSelect(char fileNameToLoad[512]) {
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
            originalImage =  LoadImage(fileNameToLoad);
            if (originalImage.height != IMAGE_SIZE ||
                originalImage.width != IMAGE_SIZE)
                ImageResize(&originalImage, IMAGE_SIZE, IMAGE_SIZE);
            originalTexture = LoadTextureFromImage(originalImage);
        }

        fileDialogState.SelectFilePressed = false;
    }
/* ---------------------------------- draw ---------------------------------- */
    if (fileDialogState.windowActive)
        GuiLock();
    if (GuiButton((Rectangle){ 20, 20, 140, 30 },
            GuiIconText(ICON_FILE_OPEN, "Open Image")))
        fileDialogState.windowActive = true;

    DrawText(fileNameToLoad, 20, 60, 10, GRAY);

    GuiUnlock();
    GuiWindowFileDialog(&fileDialogState);
    
    return originalImage;
}
