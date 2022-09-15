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
    resArr[0][12] = 3;resArr[0][13] = 3;resArr[0][14] = 4;resArr[0][15] = 4;

    arr = Image::increaseFun(arr, 4, 4);
    EXPECT_EQ (Image::compareArr(arr, resArr, 16),  true);
}