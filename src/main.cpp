#include "program_specs.h"
#include "raygui.h"
#include "image_displayer.h"
/* -------------------------------------------------------------------------- */
#include <stdlib.h> //for the themes
#include <string.h>
#include "../utils/style_dark.h"
#include "../utils/style_bluish.h"
#include "../utils/style_candy.h"
#include "../utils/style_enefete.h"
/* -------------------------------------------------------------------------- */

void FileSelect(Image &image, char fileNameToLoad[512]);
void Pixelate(Image &image, int numberOfPixels);

int main(void) {

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "WINDOW");
    SetTargetFPS(60); //can comment out
    SetWindowTitle("Nobonoko generator!");
    
    GuiLoadStyleCandy();

    char fileNameToLoad[512] = { 0 };
    Image image = { 0 };
    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            ImageDisplayer::Display();
            FileSelect(image, fileNameToLoad);
            Pixelate(image, 50);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}