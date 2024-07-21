#include "program_specs.h"
#include <raygui.h>
#include "image_displayer.h"
#include "../utils/shapes.h"

constexpr int dot = PIXEL_SIZE / 6;
constexpr int dotArea = dotNumber * dot;

Color GetRandColor(Image &image) {
    int x = GetRandomValue(0, NUMBER_OF_PIXELS - 1) * PIXEL_SIZE + PIXEL_SIZE/2;
    int y = GetRandomValue(0, NUMBER_OF_PIXELS - 1) * PIXEL_SIZE + PIXEL_SIZE/2;
    return GetImageColor(image, x, y);
}

void DrawShape(Image &image, const bool shape[dotNumber][dotNumber],
                int x, int y, const Color &color) {
    x -= dotArea/2; //offset
    y -= dotArea/2;

    
    for (int yDot = 0; yDot < dotNumber; yDot++)
        for (int xDot = 0; xDot < dotNumber; xDot++)
            if (shape[yDot][xDot])
                ImageDrawRectangle(&image,
                                    x + xDot * dot, y + yDot * dot,
                                    dot, dot,
                                    color);
                                    
    // ImageDisplayer::Update(image);
    // ImageDisplayer::Display();
}

void GenerateLines() {
    if (!GuiButton((Rectangle){ 340, 20, 140, 30 },
                GuiIconText(ICON_GEAR, "Generate")))
        return;
    Image image = ImageDisplayer::GetImage();
    if (image.data == 0)
        return;
    
    const Color color = GetRandColor(image);
    for (int y = 1; y < IMAGE_SIZE / PIXEL_SIZE; y++) {
        for (int x = 1; x < IMAGE_SIZE / PIXEL_SIZE; x++) {
            // EndDrawing();
            
            int variation = GetRandomValue(0, variations - 1);
            if ((x-1) % 4 == 0 && (y-1) % 4 == 0)
                DrawShape(image, regular1[0], 
                          x*PIXEL_SIZE, y*PIXEL_SIZE, color);
            else if ((x-1) % 4 == 0)
                DrawShape(image, vertical[variation], 
                          x*PIXEL_SIZE, y*PIXEL_SIZE, color);
            else if ((y-1) % 4 == 0)
                DrawShape(image, horizontal[variation], 
                          x*PIXEL_SIZE, y*PIXEL_SIZE, color);
            else if ((x+y) % 2 == 0)
                DrawShape(image, regular1[variation], 
                          x*PIXEL_SIZE, y*PIXEL_SIZE, color);
            else
                DrawShape(image, regular2[variation], 
                          x*PIXEL_SIZE, y*PIXEL_SIZE, color);
            
            // BeginDrawing();
        }
    }
        
        
        
    ImageDisplayer::Update(image);
}