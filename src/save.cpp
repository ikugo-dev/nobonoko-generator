#include "raylib.h"
// #include <cstring>
#include <ctime>
#include <cstdio>
#include "raygui.h"
#include "program_specs.h"

constexpr char *saveDirectory = "./saves/";

void SaveImage(Image &pixelatedImage, Image &linesImage) {
    if (GuiButton((Rectangle){ 500, 20, 140, 30 },
                GuiIconText(ICON_FILE_SAVE, "Save")) || IsKeyPressed(KEY_S)) {
        char imageDirectory[512];
        Image imageToSave = ImageCopy(linesImage);
        ImageDraw(&imageToSave, pixelatedImage,
                Rectangle{0, 0, IMAGE_SIZE, IMAGE_SIZE},
                Rectangle{DOT, DOT, IMAGE_SIZE + DOT, IMAGE_SIZE + DOT},
                WHITE);
        ImageDraw(&imageToSave, linesImage,
                Rectangle{0, 0, IMAGE_SIZE + 2*DOT, IMAGE_SIZE + 2*DOT},
                Rectangle{0, 0, IMAGE_SIZE + 2*DOT, IMAGE_SIZE + 2*DOT},
                WHITE);
        
        
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char fileName[20];

        //2024-07-22 14-09-27
        std::sprintf(fileName, "%d-%d-%d %d-%d-%d",
                1900 + ltm->tm_year,
                1 + ltm->tm_mon,
                ltm->tm_mday,
                ltm->tm_hour,
                ltm->tm_min,
                ltm->tm_sec);

        std::sprintf(imageDirectory, "%s%s%s",
                saveDirectory, fileName, ".png");

        ExportImage(imageToSave, imageDirectory);
        UnloadImage(imageToSave);
    }
}