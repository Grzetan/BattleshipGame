#pragma once
#include <iostream>
#include <vector>
#include "ship.h"

class Board{
    std::vector<Ship> ships;
    std::vector<Coords> hits;

    std::vector<size_t> shipsOnBoard;
    std::vector<size_t> shipsInStorage;
public:
    Board();
    Board(std::vector<size_t>& shipSizes);

    void shot(const Coords& c);
};