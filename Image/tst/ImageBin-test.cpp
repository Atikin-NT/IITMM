#include "gtest/gtest.h"
#include "ImageBin.h"

TEST(IncreaseTest, test1) {
    int h = 2;
    int w = 2;
    unsigned char** arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++)
        arr[i] = arr[0] + i * w;
    arr[0][0] = 1;arr[0][1] = 2;arr[0][2] = 3;arr[0][3] = 4;
    unsigned char** resArr = new unsigned char* [h*2];
    resArr[0] = new unsigned char[h * 4 * w];
    for (int i = 1; i < h * 2; i++)
        resArr[i] = resArr[0] + i * (w * 2);
    resArr[0][0] = 1;resArr[0][1] = 1;resArr[0][2] = 2;resArr[0][3] = 2;
    resArr[0][4] = 2;resArr[0][5] = 2;resArr[0][6] = 3;resArr[0][7] = 3;
    resArr[0][8] = 3;resArr[0][9] = 3;resArr[0][10] = 4;resArr[0][11] = 4;
    resArr[0][12] = 3;resArr[0][13] = 3;resArr[0][14] = 4;resArr[0][15] = 0; // !

    arr = Image::increaseFun(arr, h*2, w*2);
    EXPECT_EQ (Image::compareArr(arr, resArr, h*w*4),  true);
    delete[] arr[0];
    delete[] arr;
    delete[] resArr[0];
    delete[] resArr;
}

TEST(IncreaseTest, test2) {
    int h = 1;
    int w = 2;
    unsigned char** arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    arr[0][0] = 20;arr[0][1] = 11;
    unsigned char** resArr = new unsigned char* [h*2];
    resArr[0] = new unsigned char[h * 4 * w];
    for (int i = 1; i < h * 2; i++)
        resArr[i] = resArr[0] + i * (w * 2);
    resArr[0][0] = 20;resArr[0][1] = 15;resArr[0][2] = 11;resArr[0][3] = 11;
    resArr[0][4] = 20;resArr[0][5] = 15;resArr[0][6] = 11;resArr[0][7] = 11;

    arr = Image::increaseFun(arr, h*2, w*2);
    EXPECT_EQ (Image::compareArr(arr, resArr, h*w*4),  true);
    delete[] arr[0];
    delete[] arr;
    delete[] resArr[0];
    delete[] resArr;
}

TEST(IncreaseTest, test3) {
    int h = 3;
    int w = 2;
    unsigned char** arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++)
        arr[i] = arr[0] + i * w;
    arr[0][0] = 5;arr[0][1] = 1;arr[0][2] = 7;arr[0][3] = 2;arr[0][4] = 11;arr[0][5] = 18;
    unsigned char** resArr = new unsigned char* [h*2];
    resArr[0] = new unsigned char[h * 4 * w];
    for (int i = 1; i < h * 2; i++)
        resArr[i] = resArr[0] + i * (w * 2);
    resArr[0][0] = 5;resArr[0][1] = 3;resArr[0][2] = 1;resArr[0][3] = 1;
    resArr[0][4] = 6;resArr[0][5] = 3;resArr[0][6] = 1;resArr[0][7] = 1;
    resArr[0][8] = 7;resArr[0][9] = 4;resArr[0][10] = 2;resArr[0][11] = 2;
    resArr[0][12] = 9;resArr[0][13] = 9;resArr[0][14] = 10;resArr[0][15] = 10;
    resArr[0][16] = 11;resArr[0][17] = 14;resArr[0][18] = 18;resArr[0][19] = 18;
    resArr[0][20] = 11;resArr[0][21] = 14;resArr[0][22] = 18;resArr[0][23] = 18;

    arr = Image::increaseFun(arr, h*2, w*2);
    EXPECT_EQ (Image::compareArr(arr, resArr, h*w*4),  true);
    delete[] arr[0];
    delete[] arr;
    delete[] resArr[0];
    delete[] resArr;
}