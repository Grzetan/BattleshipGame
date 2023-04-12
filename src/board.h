#pragma once
#include <iostream>
#include <vector>
#include "ship.h"

class Board{
    std::vector<Ship> ships;
    std::vector<Coords> hits;
public:
    Board();
    Board(std::vector<size_t>& shipSizes);

    void shot(Coords& c);
};