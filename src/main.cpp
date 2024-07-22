#include "program_specs.h"
#include "raygui.h"
/* -------------------------------------------------------------------------- */
#include <stdlib.h> //for the themes
#include <string.h>
#include "../utils/styles/dark.h"
#include "../utils/styles/bluish.h"
#include "../utils/styles/candy.h"
#include "../utils/styles/enefete.h"
/* -------------------------------------------------------------------------- */

Image FileSelect(char fileNameToLoad[512]);
Image Pixelate(Image &originalImage);
Image GenerateLines(Image &pixelatedImage);
void SaveImage(Image &pixelatedImage, Image &linesImage);


int main(void) {

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "WINDOW");
    SetTargetFPS(120); //can comment out
    SetWindowTitle("Nobonoko generator!");
    
    int style = 3;
    GuiLoadStyleCandy();

    char fileNameToLoad[512] = { 0 };
    Image originalImage = { 0 };
    Image pixelatedImage = { 0 };
    Image linesImage = { 0 };

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_T)) {
            style = (style + 1) % 5;
            switch (style) {
                case 0: GuiLoadStyleDefault(); break;
                case 1: GuiLoadStyleDark();    break;
                case 2: GuiLoadStyleBluish();  break;
                case 3: GuiLoadStyleCandy();   break;
                case 4: GuiLoadStyleEnefete(); break;
            }
        }

        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            originalImage = FileSelect(fileNameToLoad);
            pixelatedImage = Pixelate(originalImage);
            linesImage = GenerateLines(pixelatedImage);
            SaveImage(pixelatedImage, linesImage);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}