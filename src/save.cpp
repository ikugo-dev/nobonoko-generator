#include "raylib.h"
#include "cstring"
#include "raygui.h"

const char *saveDirectory = "./saves/";

void SaveImage(Image &pixelatedImage, Image &linesImage) {
    if (GuiButton((Rectangle){ 500, 20, 140, 30 },
                GuiIconText(ICON_FILE_SAVE, "Save")) || IsKeyPressed(KEY_S)) {
        char imageDirectory[512] = "";
        strcpy(imageDirectory, saveDirectory);
        strcat(imageDirectory, "1.png");
        ExportImage(linesImage, imageDirectory);
    }
}