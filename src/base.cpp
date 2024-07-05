#include "simple_include.h"

GuiWindowFileDialogState fileDialogState = InitGuiWindowFileDialog(GetWorkingDirectory());

void FileSelect(Texture &texture, char fileNameToLoad[512]) {

    fileDialogState.supportDrag = false; //we can add this later
    fileDialogState.windowBounds = (Rectangle){ 100, 100, 500, 500};

    if (fileDialogState.SelectFilePressed)
    {
        // Load image file (if supported extension)
        if (IsFileExtension(fileDialogState.fileNameText, ".png"))
        {
            strcpy(fileNameToLoad, TextFormat("%s" PATH_SEPERATOR "%s", fileDialogState.dirPathText, fileDialogState.fileNameText));
            UnloadTexture(texture);
            texture = LoadTexture(fileNameToLoad);
            ImageResize(texture, )
        }

        fileDialogState.SelectFilePressed = false;
    }
    //----------------------------------------------------------------------------------
    // Draw
    //----------------------------------------------------------------------------------
        DrawText(fileNameToLoad, 208, GetScreenHeight() - 20, 10, GRAY);
        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (fileDialogState.windowActive)
            GuiLock();
        if (GuiButton((Rectangle){ 20, 20, 140, 30 }, GuiIconText(ICON_FILE_OPEN, "Open Image")))
            fileDialogState.windowActive = true;
        GuiUnlock();
        // GUI: Dialog Window
        //--------------------------------------------------------------------------------
        GuiWindowFileDialog(&fileDialogState);
        //--------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------
}

// // void BaseFunc(void) {
// //     if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

// //     if (showMessageBox)
// //     {
// //         int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
// //             "#191#Message Box", "Hi! This is a message!", "Nice;Cool");
// //         if (result >= 0) showMessageBox = false;
// //     }
// // }