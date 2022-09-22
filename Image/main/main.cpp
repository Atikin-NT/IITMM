#include <iostream>
#include "ImageTXT.h"
#include "ImageBin.h"
#include "IMethod.h"

using namespace std;

template <typename T>
void fill(ImageTXT& img, T method){
    int w = img.getW(), h = img.getH();
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            img.Get_Pixel(i, j) = method->getValue(j, i);
}

int main() {
    ImageTXT imgTXT;
    try {
        imgTXT.getFromFile("image-input.txt");
    }
    catch (const char* err){
        std::cout << err << std::endl;
    }
    imgTXT.print();
    imgTXT.increase();
    imgTXT.print();
    fill(imgTXT, new FillBlackWhite());
    imgTXT.print();
    try {
        imgTXT.writeToFile("image-output.txt");
    }
    catch (const char* err){
        std::cout << err << std::endl;
    }

    return 0;
}
