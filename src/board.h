#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <SDL2/SDL.h>
#include "ship.h"

#define CELL_COUNT 10

class Board{
    static const size_t cellCount = CELL_COUNT, cellSize = 40;
    const size_t centerX, centerY;

    std::vector<Ship*> ships;
    std::vector<Coords> hits;
    std::vector<CellType> board;

public:
    Board();
    Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_);

    void shot(const Coords& c);

    void render(SDL_Renderer* renderer, bool visible);

    bool boardValid();
};