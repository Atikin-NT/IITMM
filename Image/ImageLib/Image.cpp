#include <iostream>
#include <cstring>
#include "Image.h"

using namespace std;

Image::Image(int _h, int _w) {
    h = _h;
    w = _w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    memset(arr[0], 0, h*w);
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
}

Image::Image(const Image &a) {
    h = a.h;
    w = a.w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++)
        arr[i] = arr[0] + i * w;

    for (int i = 0; i < h*w; i++)
        arr[0][i] = a.arr[0][i];
}

Image &Image::operator=(const Image &image) {
    if (this == &image)
        return *this;

    delete[] arr[0];
    delete[] arr;

    h = image.h;
    w = image.w;

    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++)
        arr[i] = arr[0] + i * w;

    for (int i = 0; i < h*w; i++)
        arr[0][i] = image.arr[0][i];

    return *this;
}

Image::~Image() {
    delete[] arr[0];
    delete[] arr;
}

unsigned char &Image::Get_Pixel(int _h, int _w) {
    if (_w < 0 || _h < 0 || _w >= w || _h >= h)
    {
        throw 1;
    }
    return arr[_h][_w];
}

void Image::increase() {
    h *= 2;
    w *= 2;
    arr = increaseFun(arr, h, w);
}

void Image::decrease(int volume) {
    if(volume > h || volume > w || h%volume != 0 || w%volume != 0)
        throw "VolumeError: volume bigger then image";
    int newH = h / volume; // = 2
    int newW = w / volume;

    unsigned char** newArrH = new unsigned char* [newH];
    newArrH[0] = new unsigned char[newH * newW];
    for (int i = 1; i < newH; i++)
        newArrH[i] = newArrH[0] + i * newW;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            newArrH[i / volume][j / volume] += arr[i][j];
        }
    }

    for (int i = 0; i < newH*newW; i++) {
        newArrH[0][i] /= 4;
    }
    delete[] arr[0];
    delete[] arr;

    arr = newArrH;
    h = newH;
    w = newW;
}

void Image::print() {
    for(int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            printf("%d ", arr[i][j]);
        }
        cout << endl;
    }
}

int Image::getH() {
    return h;
}

int Image::getW() {
    return w;
}

void Image::reload(int _h, int _w) {
    h = _h;
    w = _w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    memset(arr[0], 0, h*w);
    for (int i = 1; i < h; i++)
    {
        arr[i] = arr[0] + i * w;
    }
}

unsigned char** Image::increaseFun(unsigned char** arrIncrease, int h, int w) {
    unsigned char** newArrH = new unsigned char* [h];
    newArrH[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++)
        newArrH[i] = newArrH[0] + i * w;

    newArrH[0][0] = arrIncrease[0][0];
    for (int j = 2; j < w-1; j+=2) {
        newArrH[0][j] = arrIncrease[0][j/2];
        newArrH[0][j-1] = (newArrH[0][j-2] + newArrH[0][j]) / 2;
    }
    for (int i = 2; i < h-1; i+=2) {
        newArrH[i][0] = arrIncrease[i/2][0];
        newArrH[i-1][0] = (newArrH[i-2][0] + newArrH[i][0]) / 2;
        for (int j = 2; j < w-1; j+=2) {
            newArrH[i][j] = arrIncrease[i/2][j/2];
            newArrH[i-1][j] = (newArrH[i-2][j] + newArrH[i][j]) / 2;

            newArrH[i][j-1] = (newArrH[i][j-2] + newArrH[i][j]) / 2;
            newArrH[i-1][j-1] = (newArrH[i-2][j-1] + newArrH[i][j-1]) / 2;
        }
    }

    for (int i = 0; i < w; i++) {
        newArrH[h-1][i] = newArrH[h-2][i];
    }

    for (int i = 0; i < h; i++) {
        newArrH[i][w-1] = newArrH[i][w-2];
    }

    delete[] arrIncrease[0];
    delete[] arrIncrease;

    return newArrH;
}

bool Image::compareArr(unsigned char **arr1, unsigned char **arr2, int len) {
    for (int i = 0; i < len; i++) {
        if(arr1[0][i] != arr2[0][i]) return false;
    }
    return true;
}