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
    for (int i = 0; i < h*w; i++) {
        arr[0][i] = rand() % 100 + 1;
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
    int volume = 2;
    int newH = h * volume; // = 2
    int newW = w * volume;

    unsigned char** newArrH = new unsigned char* [newH];
    newArrH[0] = new unsigned char[newH * newW];
    for (int i = 1; i < newH; i++)
        newArrH[i] = newArrH[0] + i * newW;

    for (int i = 0; i < newH; i+=volume) {
        for (int j = 0; j < newW; j+=volume) {
            newArrH[i][j] = arr[i/volume][j/volume];
        }
    }

    for (int i = 0; i < newH - 1; i+=volume) {
        for (int j = 1; j < newW - 1; j+=volume) {
            newArrH[i][j] = (newArrH[i][j-1] + newArrH[i][j+1]) / 2;
        }
    }

    for (int i = 1; i < newH - 1; i+=volume) {
        for (int j = 0; j < newW; j++) {
            newArrH[i][j] = (newArrH[i-1][j] + newArrH[i+1][j]) / 2;
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
    if(volume > h || volume > w)
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

/*
 * 0  [1122]            12
 * 1  [1122]   => /2    00
 * 2  [3344]
 * 3  [3344]
 */

void Image::printImage() {
    for(int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            printf("%d ", arr[i][j]);
        }
        cout << endl;
    }
}