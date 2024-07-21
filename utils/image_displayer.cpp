#include "../lib/program_specs.h"
#include "../lib/image_displayer.h"

Image ImageDisplayer::image = {0};
Texture2D ImageDisplayer::texture;

void ImageDisplayer::ImageDisplayer::Display() {
    if (image.data == 0)
        return;
    
    DrawTexture(ImageDisplayer::texture,
                GetScreenWidth()/2 - IMAGE_SIZE/2,
                GetScreenHeight()/2 - IMAGE_SIZE/2 - 5,
                WHITE);
    DrawRectangleLines(GetScreenWidth()/2 - IMAGE_SIZE/2,
                       GetScreenHeight()/2 - IMAGE_SIZE/2 - 5,
                       IMAGE_SIZE,
                       IMAGE_SIZE,
                       BLACK);
}

void ImageDisplayer::Update(Image &image) {
    // if (ImageDisplayer::image.data != 0)
    //     UnloadImage(ImageDisplayer::image);
    
    if (image.height != IMAGE_SIZE || image.width != IMAGE_SIZE)
        ImageResize(&image, IMAGE_SIZE, IMAGE_SIZE);
    
    UnloadTexture(ImageDisplayer::texture);
    
    ImageDisplayer::image = image;
    ImageDisplayer::texture = LoadTextureFromImage(image);
}

Image ImageDisplayer::GetImage() {
    return ImageDisplayer::image;
}