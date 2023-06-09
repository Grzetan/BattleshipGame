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
    int selectedShip = -1;

    void setupShips(std::vector<size_t>& shipSizes);

public:
    Board();
    Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_);

    bool shot(int x, int y);

    void render(SDL_Renderer* renderer, bool visible);

    bool boardValid();

    Coords getClickedCell(int x, int y);

    void selectShip(int x, int y);

    void mouseup();

    void mousemove(int x, int y);

    void resetBoard(std::vector<size_t>& shipSizes);

    bool isGameOver();
};