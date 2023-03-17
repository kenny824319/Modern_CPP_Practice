#include "ImageManager.h"

void ImageManager::SetNewImg(int w, int h)
{
    img.reset(new Image(w, h));
}