#include "Image.h"

Image::Image()
{
    ReleaseAll();
}

Image::Image(int _w, int _h)
{
    w = _w;
    h = _h;
    if(w * h <= 0)
    {
        ReleaseAll();
    }
    else
    {
        pImage = new unsigned char [w * h];
    }
}

Image::~Image()
{
    ReleaseAll();
}

void Image::ReleaseAll()
{
    w = h = 0;
    if(pImage)
    {
        delete [] pImage;
    }
    pImage = nullptr;
}