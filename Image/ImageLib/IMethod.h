#pragma once

class IMethod{
public:
    virtual int getValue(int w, int h) = 0;
};

class FillWhite: public IMethod{
public:
    int getValue(int w, int h) override{
        return 255;
    }
};

class FillBlackWhite: public IMethod{
public:
    int getValue(int w, int h) override{
        if((w + h) % 2 == 0) return 0;
        return 255;
    }
};
