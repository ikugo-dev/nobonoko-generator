#include "program_specs.h"
#include <raygui.h>
#include "../utils/shapes.h"

constexpr int dot = PIXEL_SIZE / 5;
constexpr int dotArea = dotNumber * dot;

Color GetRandColor(Image &image);
void DrawShape(Image &image, const bool shape[dotNumber][dotNumber],
                int x, int y, const Color &color);


Image GenerateLines(Image &pixelatedImage) {
    static Image linesImage;
    static Texture2D linesTexture;
    
    DrawTexture(linesTexture,
                GetScreenWidth()/2 - IMAGE_SIZE/2 - 2*dot,
                GetScreenHeight()/2 - IMAGE_SIZE/2 - 2*dot,
                WHITE);


    if (!GuiButton((Rectangle){ 340, 20, 140, 30 },
                GuiIconText(ICON_GEAR, "Generate")))
        return linesImage;

    if (pixelatedImage.data == 0)
        return linesImage;
    
    const Color color = GetRandColor(pixelatedImage);
    linesImage = GenImageColor(IMAGE_SIZE + (4*dot), IMAGE_SIZE + (4*dot), BLANK);

    for (int y = 0; y <= (IMAGE_SIZE + 4*dot) / PIXEL_SIZE; y++) {
        for (int x = 0; x <= (IMAGE_SIZE + 4*dot) / PIXEL_SIZE; x++) {
            // EndDrawing();
            
            int variation = GetRandomValue(0, variations - 1);
            if (x % 4 == 0 && y % 4 == 0)
                DrawShape(linesImage, regular1[0], 
                          x*PIXEL_SIZE + 2*dot, y*PIXEL_SIZE + 2*dot, color);
            else if (x % 4 == 0)
                DrawShape(linesImage, vertical[variation], 
                          x*PIXEL_SIZE + 2*dot, y*PIXEL_SIZE + 2*dot, color);
            else if (y % 4 == 0)
                DrawShape(linesImage, horizontal[variation], 
                          x*PIXEL_SIZE + 2*dot, y*PIXEL_SIZE + 2*dot, color);
            else if ((x+y) % 2 == 0)
                DrawShape(linesImage, regular1[variation], 
                          x*PIXEL_SIZE + 2*dot, y*PIXEL_SIZE + 2*dot, color);
            else
                DrawShape(linesImage, regular2[variation], 
                          x*PIXEL_SIZE + 2*dot, y*PIXEL_SIZE + 2*dot, color);
            
            // BeginDrawing();
        }
    }
    ImageDrawRectangleLines(&linesImage, Rectangle{0, 0,
                                            IMAGE_SIZE + 4*dot,
                                            IMAGE_SIZE + 4*dot},
                            (2*dot), color);
    linesTexture = LoadTextureFromImage(linesImage);
    return linesImage;

    // linesDisplayer = LoadTextureFromImage(lines);
    // lines = GenImageColor(IMAGE_SIZE, IMAGE_SIZE, BLANK);
}


void DrawShape(Image &image, const bool shape[dotNumber][dotNumber],
                int x, int y, const Color &color) {
    x -= dotArea/2; //offset
    y -= dotArea/2;

    
    for (int yDot = 0; yDot < dotNumber; yDot++)
        for (int xDot = 0; xDot < dotNumber; xDot++) {
            int xPos = x + xDot * dot;
            int yPos = y + yDot * dot;
            if (xPos < 0 || xPos >= IMAGE_SIZE + 4*dot ||
                yPos < 0 || yPos >= IMAGE_SIZE + 4*dot)
                continue;
            if (shape[yDot][xDot])
                ImageDrawRectangle(&image,
                                    xPos, yPos,
                                    dot, dot,
                                    color);
        }
                                    
    // ImageDisplayer::Update(image);
    // ImageDisplayer::Display();
}

Color GetRandColor(Image &image) {
    int x = GetRandomValue(0, IMAGE_SIZE - 1);
    int y = GetRandomValue(0, IMAGE_SIZE - 1);
    return GetImageColor(image, x, y);
}