#pragma once
#include "Image.h"
#include <memory>

class ImageManager
{
    private:
        std::unique_ptr<Image> img;
    public:
        void SetNewImg(int w, int h);
};