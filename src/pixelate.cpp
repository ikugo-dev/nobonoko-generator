#include "raygui.h"
#include "image_displayer.h"

void Pixelate(Image &image) {

    if (GuiButton((Rectangle){ 180, 20, 140, 30 },
                GuiIconText(ICON_1UP, "Pixelate"))) {
        ImageColorInvert(&image);
        ImageDrawRectangle(&image, 50, 50, 100, 100, RED);



        ImageDisplayer::Update(image);
    }

}