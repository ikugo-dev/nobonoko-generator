#include "raylib.h"
#include "cstring"
#include "image_displayer.h"

const char *saveDirectory = "./saves/";

void SaveImage() {
    //TODO: dodaj ImageDisplayer::GetImage() da bi mogo da ga sacuvas
    //posto sad ne smes da menjas image, a u ImageDisplayer ti je tekstura
    //koju zelis da sacuvas
    if (IsKeyPressed(KEY_S)) {
        char imageDirectory[512] = "";
        strcpy(imageDirectory, saveDirectory);
        strcat(imageDirectory, "1.png");
        ExportImage(ImageDisplayer::GetImage(), imageDirectory);
    }
}