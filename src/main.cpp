#include "raygui.h"
#include "image_displayer.h"

void FileSelect(Image &image, char fileNameToLoad[512]);
void Pixelate(Image &image);


int main(void) {
    constexpr int SCREEN_W = 800;
    constexpr int SCREEN_H = 800;
    
    InitWindow(SCREEN_W, SCREEN_H, "WINDOW");
    SetTargetFPS(60); //can comment out
    SetWindowTitle("Nobonoko generator!");

    char fileNameToLoad[512] = { 0 };
    Image image = { 0 };
    Texture imageDisplay;

    while (!WindowShouldClose())
    {
        // BeginDrawing();
        // ClearBackground(RAYWHITE);
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

            // ImageDisplayer::Display();
            FileSelect(image, fileNameToLoad);
            Pixelate(image);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}