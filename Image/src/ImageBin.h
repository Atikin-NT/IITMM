#pragma once
#include "Image.h"
#include <fstream>
#include <string>

using namespace std;

class ImageBin: public Image {
    ofstream ofile;
    ifstream ifile;
public:
    void writeToFile(string filename);
    void getFromFile(string filename);
};
