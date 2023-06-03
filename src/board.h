#pragma once
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "ship.h"

class Board{
    static const size_t cellCount = 10, cellSize = 40;
    const size_t centerX, centerY;

    std::vector<Ship> ships;
    std::vector<Coords> hits;

    std::vector<size_t> shipsOnBoard;
    std::vector<size_t> shipsInStorage;
public:
    Board();
    Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_);

    void shot(const Coords& c);

    void render(SDL_Renderer* renderer, bool visible);
};