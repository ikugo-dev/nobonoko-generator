#include "image_displayer.h"

Texture2D *ImageDisplayer::texture = nullptr;

void ImageDisplayer::ImageDisplayer::Display() {
    if (ImageDisplayer::texture == nullptr)
        return;
    DrawTexture(*ImageDisplayer::texture,
                GetScreenWidth()/2 - ImageDisplayer::texture->width/2,
                GetScreenHeight()/2 - ImageDisplayer::texture->height/2 - 5,
                WHITE);
    DrawRectangleLines(GetScreenWidth()/2 - ImageDisplayer::texture->width/2,
                       GetScreenHeight()/2 - ImageDisplayer::texture->height/2 - 5,
                       ImageDisplayer::texture->width,
                       ImageDisplayer::texture->height,
                       BLACK);
}

void ImageDisplayer::Update(Image &texture) {
    *ImageDisplayer::texture = LoadTextureFromImage(texture);
}