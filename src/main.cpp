#include "program_specs.h"
#include "raygui.h"
#include "image_displayer.h"
/* -------------------------------------------------------------------------- */
#include <stdlib.h> //for the themes
#include <string.h>
#include "../utils/styles/dark.h"
#include "../utils/styles/bluish.h"
#include "../utils/styles/candy.h"
#include "../utils/styles/enefete.h"
/* -------------------------------------------------------------------------- */

void FileSelect(Image &image, char fileNameToLoad[512]);
void Pixelate(Image &image);
void GenerateLines();
void SaveImage();


int main(void) {

    InitWindow(SCREEN_SIZE, SCREEN_SIZE, "WINDOW");
    SetTargetFPS(120); //can comment out
    SetWindowTitle("Nobonoko generator!");
    
    int style = 3;
    GuiLoadStyleCandy();

    char fileNameToLoad[512] = { 0 };
    Image image = { 0 };

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_T)) {
            style = (style + 1) % 5;
            switch (style) {
                case 0: GuiLoadStyleDefault(); break;
                case 1: GuiLoadStyleDark(); break;
                case 2: GuiLoadStyleBluish(); break;
                case 3: GuiLoadStyleCandy(); break;
                case 4: GuiLoadStyleEnefete(); break;
            }
        }

        BeginDrawing();

            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            ImageDisplayer::Display();
            FileSelect(image, fileNameToLoad);
            Pixelate(image);
            GenerateLines();
            SaveImage();
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}