#pragma once
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION

class ImageDisplayer {
private:
    static Texture2D *texture;
public:
    static void Display();
    static void Update(Image &image);
};