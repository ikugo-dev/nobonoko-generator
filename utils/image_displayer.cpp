#include "../lib/image_displayer.h"

Image ImageDisplayer::image = {0};
Texture2D ImageDisplayer::texture;

void ImageDisplayer::ImageDisplayer::Display() {
    if (image.data == 0)
        return;
    
    DrawTexture(ImageDisplayer::texture,
                GetScreenWidth()/2 - ImageDisplayer::texture.width/2,
                GetScreenHeight()/2 - ImageDisplayer::texture.height/2 - 5,
                WHITE);
    DrawRectangleLines(GetScreenWidth()/2 - ImageDisplayer::texture.width/2,
                       GetScreenHeight()/2 - ImageDisplayer::texture.height/2 - 5,
                       ImageDisplayer::texture.width,
                       ImageDisplayer::texture.height,
                       BLACK);
}

void ImageDisplayer::Update(Image &image) {
    ImageDisplayer::image = image;
    ImageDisplayer::texture = LoadTextureFromImage(image);
}