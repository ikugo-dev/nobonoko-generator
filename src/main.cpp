#include "raygui.h"

void FileSelect(Texture &texture, char fileNameToLoad[512]);

int main(void)
{
    constexpr int SCREEN_W = 800;
    constexpr int SCREEN_H = 800;
    
    InitWindow(SCREEN_W, SCREEN_H, "WINDOW");
    SetTargetFPS(60); //can comment out

    char fileNameToLoad[512] = { 0 };
    Texture texture = { 0 };

    while (!WindowShouldClose())
    {
        // BeginDrawing();
        // ClearBackground(RAYWHITE);
        BeginDrawing();
            ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
            DrawRectangleLines(SCREEN_W/2 - texture.width/2, SCREEN_H/2 - texture.height/2 - 5, texture.width, texture.height, BLACK);
            DrawTexture(texture, SCREEN_W/2 - texture.width/2, SCREEN_H/2 - texture.height/2 - 5, WHITE);

            FileSelect(texture, fileNameToLoad);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}