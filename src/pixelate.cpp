#include "program_specs.h"
#include "raygui.h"
#include "image_displayer.h"

void Pixelate(Image &image, int numberOfPixels) {

    if (GuiButton((Rectangle){ 180, 20, 140, 30 },
                GuiIconText(ICON_1UP, "Pixelate"))) {
        int pixelSize = IMAGE_SIZE / numberOfPixels;
        int subPixelDensity = pixelSize * pixelSize;

        Image newImage = ImageCopy(image);
        ImageClearBackground(&newImage, RAYWHITE);

        for (int x = 0; x < numberOfPixels; x++) {
            for (int y = 0; y < numberOfPixels; y++) {

                unsigned long r = 0, g = 0, b = 0, a = 0;
                for (int xSubPixel = 0; xSubPixel < pixelSize; xSubPixel++) {
                    for (int ySubPixel = 0; ySubPixel < pixelSize; ySubPixel++) {
                        Color subPixel = GetImageColor(image,
                                                    xSubPixel + x*pixelSize,
                                                    ySubPixel + y*pixelSize);
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
                                   x * pixelSize, y * pixelSize,
                                   pixelSize, pixelSize,
                                   pixelColor);
            }
        }
        ImageDisplayer::Update(newImage);
    }

}