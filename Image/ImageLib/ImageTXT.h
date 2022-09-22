#pragma once

#include "Image.h"
#include <fstream>
#include <string>

using namespace std;

class ImageTXT {
    Image* img;
    ofstream ofile;
    ifstream ifile;
public:
    ImageTXT();
    ~ImageTXT();

    void writeToFile(string filename);
    void getFromFile(string filename);

    void print();
    void increase();
    void decrease(int volume);
    unsigned char& Get_Pixel(int _h, int _w);
    int getH();
    int getW();



};
