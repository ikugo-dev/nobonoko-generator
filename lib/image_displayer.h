#pragma once
#include "raylib.h"

class ImageDisplayer {
private:
    static Image image;
    static Texture2D texture;
public:
    static void Display();
    static void Update(Image &image);
    static Image GetImage();
};