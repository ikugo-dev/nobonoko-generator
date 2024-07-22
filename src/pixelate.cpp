#include "program_specs.h"
#include "raygui.h"

Image Pixelate(Image &originalImage) {
    static Image pixelatedImage;
    static Texture2D pixelatedTexture;
    DrawTexture(pixelatedTexture,
                GetScreenWidth()/2 - IMAGE_SIZE/2,
                GetScreenHeight()/2 - IMAGE_SIZE/2,
                WHITE);

    if (!GuiButton((Rectangle){ 180, 20, 140, 30 },
                GuiIconText(ICON_1UP, "Pixelate")))
        return pixelatedImage;

    if (originalImage.data == 0)
        return pixelatedImage;
    
    int subPixelDensity = PIXEL_SIZE * PIXEL_SIZE;

    Image newImage = ImageCopy(originalImage);
    ImageClearBackground(&newImage, RAYWHITE);

    for (int x = 0; x < NUMBER_OF_PIXELS; x++) {
        for (int y = 0; y < NUMBER_OF_PIXELS; y++) {
            unsigned long r = 0, g = 0, b = 0, a = 0;
            for (int xSubPixel = 0; xSubPixel < PIXEL_SIZE; xSubPixel++) {
                for (int ySubPixel = 0; ySubPixel < PIXEL_SIZE; ySubPixel++) {
                    Color subPixel = GetImageColor(originalImage,
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
    pixelatedImage = ImageCopy(newImage);
    pixelatedTexture = LoadTextureFromImage(pixelatedImage);
    return pixelatedImage;
}