
#include "ImageBin.h"

void ImageBin::getFromFile(std::string filename) {
    ifile.open(filename, ios::binary);
    if(!ifile.is_open()) return;

    int w = 1, h = 1;
    ifile.read(reinterpret_cast<char*>(&h), sizeof(int));
    ifile.read(reinterpret_cast<char*>(&w), sizeof(int));

    reload(h, w);

    ifile.read(reinterpret_cast<char*>(arr[0]), sizeof(unsigned char)*h*w);
    cout << endl << w << "x" << h << endl;
    ifile.close();
}

void ImageBin::writeToFile(std::string filename) {
    ofile.open(filename, ios::binary);
    if(!ofile.is_open()) return;
    ofile << getW() << " " << getH() << endl;

    int h = getH();
    int w = getW();

    ofile.write(reinterpret_cast<char*>(&h), sizeof(int));
    ofile.write(reinterpret_cast<char*>(&w), sizeof(int));
    ofile.write(reinterpret_cast<char*>(arr[0]), sizeof(unsigned char)*h*w);

    ofile.close();
}