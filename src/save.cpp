#include "raylib.h"
#include "cstring"
#include "raygui.h"
#include "program_specs.h"

const char *saveDirectory = "./saves/";

void SaveImage(Image &pixelatedImage, Image &linesImage) {
    if (GuiButton((Rectangle){ 500, 20, 140, 30 },
                GuiIconText(ICON_FILE_SAVE, "Save")) || IsKeyPressed(KEY_S)) {
        char imageDirectory[512] = "";
        strcpy(imageDirectory, saveDirectory);
        strcat(imageDirectory, "1.png");
        Image imageToSave = ImageCopy(linesImage);
        ImageDraw(&imageToSave, pixelatedImage,
                Rectangle{0, 0, IMAGE_SIZE, IMAGE_SIZE},
                Rectangle{DOT, DOT, IMAGE_SIZE + DOT, IMAGE_SIZE + DOT},
                WHITE);
        ImageDraw(&imageToSave, linesImage,
                Rectangle{0, 0, IMAGE_SIZE + 2*DOT, IMAGE_SIZE + 2*DOT},
                Rectangle{0, 0, IMAGE_SIZE + 2*DOT, IMAGE_SIZE + 2*DOT},
                WHITE);
        ExportImage(imageToSave, imageDirectory);
        UnloadImage(imageToSave);
    }
}