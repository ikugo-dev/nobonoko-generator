#include "program_specs.h"
#include "raygui.h"
#include "image_displayer.h"

void Pixelate(Image &image) {

    if (!GuiButton((Rectangle){ 180, 20, 140, 30 },
                GuiIconText(ICON_1UP, "Pixelate")))
        return;
    if (ImageDisplayer::GetImage().data == 0)
        return;
    
    
    int subPixelDensity = PIXEL_SIZE * PIXEL_SIZE;

    Image newImage = ImageCopy(image);
    ImageClearBackground(&newImage, RAYWHITE);

    for (int x = 0; x < NUMBER_OF_PIXELS; x++) {
        for (int y = 0; y < NUMBER_OF_PIXELS; y++) {
            unsigned long r = 0, g = 0, b = 0, a = 0;
            for (int xSubPixel = 0; xSubPixel < PIXEL_SIZE; xSubPixel++) {
                for (int ySubPixel = 0; ySubPixel < PIXEL_SIZE; ySubPixel++) {
                    Color subPixel = GetImageColor(image,
                                                xSubPixel + x*PIXEL_SIZE,
                                                ySubPixel + y*PIXEL_SIZE);
                    r += subPixel.r;
                    g += subPixel.g;
                    b += subPixel.b;
                    a += subPixel.a;
                }
            }
            Color pixelColor = Color{(unsigned char)(r / subPixelDensity),
                                    (unsigned char)(g / subPixelDensity),
                                    (unsigned char)(b / subPixelDensity),
                                    (unsigned char)(a / subPixelDensity)};
            // pixelColor = (x+y) % 2 ? RED : BLUE;
            ImageDrawRectangle(&newImage,
                            x * PIXEL_SIZE, y * PIXEL_SIZE,
                            PIXEL_SIZE, PIXEL_SIZE,
                            pixelColor);
        }
    }
    ImageDisplayer::Update(newImage);
}