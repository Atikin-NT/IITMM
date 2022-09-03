#include <iostream>
#include "Image.h"

using namespace std;

int main() {
    Image image(4, 6);
    image.printImage();
    try {
        image.decrease(2);
    }
    catch (const char* msg){
        cout << msg << endl;
    }
    cout << endl;
    image.printImage();
    image.increase();
    cout << endl;
    image.printImage();
    return 0;
}
