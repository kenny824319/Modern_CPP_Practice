#pragma once

class Image
{
    private:
        int w, h;
        unsigned char *pImage;
    public:
        Image();
        Image(int _w, int _h);
        ~Image();
        void ReleaseAll();
};