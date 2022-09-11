#include "ImageTXT.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ImageTXT::ImageTXT() {
    img = nullptr;
}
ImageTXT::~ImageTXT() {
    delete img;
}

void ImageTXT::getFromFile(std::string filename) {
    ifile.open(filename, ios::in);
    if(!ifile.is_open()) return;

    int w = 1, h = 1;
    ifile >> h;
    ifile >> w;

    delete img;
    img = new Image(h, w);

    int num = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ifile >> num;
            img->Get_Pixel(i, j) = num;
        }
    }
    cout << endl << w << "x" << h << endl;
    ifile.close();
}

void ImageTXT::writeToFile(std::string filename) {
    ofile.open(filename, ios::out);
    if(!ofile.is_open()) return;
    ofile << img->getW() << " " << img->getH() << endl;

    for (int i = 0; i < img->getH(); i++) {
        for (int j = 0; j < img->getW(); j++) {
            ofile << (int)img->Get_Pixel(i, j);
            if(j != img->getW() - 1) ofile << " ";
        }
        if(i != img->getH() - 1) ofile << endl;
    }

    ofile.close();
}

void ImageTXT::print() {
    img->print();
}
void ImageTXT::increase() {
    img->increase();
}
void ImageTXT::decrease(int volume) {
    img->decrease(volume);
}
