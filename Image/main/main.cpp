#include <iostream>
#include "Image.h"
#include "ImageTXT.h"
#include "ImageBin.h"
#include "IMethod.h"

using namespace std;

template <typename T>
void fill(Image& img, T method){
    int w = img.getW(), h = img.getH();
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            img.Get_Pixel(h, w) = method->getValue(w, h);
}

int main() {
    ImageTXT imgBin;
    imgBin.getFromFile("const.txt");
    imgBin.print();
//    fill(imgBin, new FillWhite());
    imgBin.increase();
//    imgBin.print();
    imgBin.writeToFile("image-output.bin");

    return 0;
}
