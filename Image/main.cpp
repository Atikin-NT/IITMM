#include <iostream>
#include "Image.h"
#include "ImageTXT.h"
#include "ImageBin.h"

using namespace std;

int main() {
    ImageBin imgBin;
    imgBin.getFromFile("const.txt");
    imgBin.print();
    imgBin.increase();
    imgBin.print();
    imgBin.writeToFile("image-output.bin");

    return 0;
}
