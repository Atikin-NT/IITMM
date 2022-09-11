#include <iostream>
#include "Image.h"
#include "ImageTXT.h"
#include "ImageBin.h"

using namespace std;

int main() {
//    ImageTXT imgTXT;
//    imgTXT.getFromFile("const.txt");
//    imgTXT.print();
//    imgTXT.increase();
//    imgTXT.print();
//    imgTXT.writeToFile("tmp.txt");

    ImageBin imgBin;
    imgBin.getFromFile("const.txt");
    imgBin.print();
    imgBin.increase();
    imgBin.print();
    imgBin.writeToFile("tmp.txt");

    return 0;
}
