//
// Created by atikin on 03.09.22.
//
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
    int newH = h * 2; // = 2
    int newW = w * 2;

    unsigned char** newArrH = new unsigned char* [newH];
    newArrH[0] = new unsigned char[newH * newW];
    for (int i = 1; i < newH; i++)
        newArrH[i] = newArrH[0] + i * newW;

    newArrH[0][0] = arr[0][0];
    for (int j = 2; j < newW-1; j+=2) {
        newArrH[0][j] = arr[0][j/2];
        newArrH[0][j-1] = (newArrH[0][j-2] + newArrH[0][j]) / 2;
    }
    for (int i = 2; i < newH-1; i+=2) {
        newArrH[i][0] = arr[i/2][0];
        newArrH[i-1][0] = (newArrH[i-2][0] + newArrH[i][0]) / 2;
        for (int j = 2; j < newW-1; j+=2) {
            newArrH[i][j] = arr[i/2][j/2];
            newArrH[i-1][j] = (newArrH[i-2][j] + newArrH[i][j]) / 2;

            newArrH[i][j-1] = (newArrH[i][j-2] + newArrH[i][j]) / 2;
            newArrH[i-1][j-1] = (newArrH[i-2][j-1] + newArrH[i][j-1]) / 2;
        }
    }

    for (int i = 0; i < newW; i++) {
        newArrH[newH-1][i] = newArrH[newH-2][i];
    }

    for (int i = 0; i < newH; i++) {
        newArrH[i][newW-1] = newArrH[i][newW-2];
    }

    delete[] arr[0];
    delete[] arr;

    arr = newArrH;
    h = newH;
    w = newW;
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