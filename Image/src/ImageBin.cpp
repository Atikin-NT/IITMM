
#include "ImageBin.h"

void ImageBin::getFromFile(std::string filename) {
    ifile.open(filename, ios::binary);
    if(!ifile.is_open()) return;

    int w = 1, h = 1;
    ifile >> h;
    ifile >> w;

    reload(h, w);

    int num = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ifile >> num;
            Get_Pixel(i, j) = num;
        }
    }
    cout << endl << w << "x" << h << endl;
    ifile.close();
}

void ImageBin::writeToFile(std::string filename) {
    ofile.open(filename, ios::binary);
    if(!ofile.is_open()) return;
    ofile << getW() << " " << getH() << endl;

    for (int i = 0; i < getH(); i++) {
        for (int j = 0; j < getW(); j++) {
            ofile << (int)Get_Pixel(i, j);
            if(j != getW() - 1) ofile << " ";
        }
        if(i != getH() - 1) ofile << endl;
    }

    ofile.close();
}