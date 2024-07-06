#pragma once
#include "raylib.h"

class ImageDisplayer {
private:
    static Texture2D *texture;
public:
    static void Display();
    static void Update(Image &image);
};