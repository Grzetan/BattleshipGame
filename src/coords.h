#pragma once
#include <iostream>

struct Coords{
    int x;
    int y;

    Coords(int x_, int y_) : x(x_), y(y_){};

    bool operator==(const Coords& c);
    bool operator==(int p);
    Coords operator+=(const Coords& c);
    Coords operator+(const Coords& c);
    Coords operator-(const Coords& c);
    Coords operator*=(int p);
    Coords operator*(int p);

    void increment(size_t cellCount);

    bool empty();
};

enum CellType{
    EMPTY, SHIP, HIT_SHIP, HIT
};