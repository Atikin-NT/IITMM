#pragma once
#include <iostream>

class Image
{
private:
    int h;
    int w;
    unsigned char** arr;
public:
    Image(int _h = 1, int _w = 1);
    Image(const Image& a);
    Image& operator =(const Image& image);
    ~Image();
    unsigned char& Get_Pixel(int _h, int _w);

    void increase();
    void decrease(int volume);

    void print();
    int getH();
    int getW();

    void reload(int h, int w);

    static unsigned char** increaseFun(unsigned char** arr, int h, int w);
    int decreaseFun(int volume);
    static bool compareArr(unsigned char** arr1, unsigned char** arr2, int len);
};
