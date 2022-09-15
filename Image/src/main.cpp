#include "ImageBin.h"

int main() {
    ImageBin imgBin;
    imgBin.getFromFile("const.txt");
    imgBin.print();
    imgBin.increase();
    imgBin.print();
    imgBin.writeToFile("tmp.txt");

    return 0;
}