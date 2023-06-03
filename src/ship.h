#pragma once
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "coords.h"

const Coords up {0, 1};
const Coords down {0, -1};
const Coords left {-1, 0};
const Coords right {1, 0};

const std::vector<Coords> fieldsToCheck = { {-1,  1}, {0,  1}, {1,  1},
                                            {-1,  0}, {0,  0}, {1,  0},
                                            {-1, -1}, {0, -1}, {1, -1} };

class Ship{
    const size_t n_blocks;
    bool is_alive;
    Coords origin;
    Coords direction;
    bool valid;
    std::vector<size_t> hits; // Which part of ship was hit 1...n_blocks

public:
    Ship(size_t size) : n_blocks(size), 
                        is_alive(true),
                        origin({0, 0}),
                        direction(up),
                        valid(false){};

    void move(const Coords& c);
    void shot(const Coords& c);
    void rotateLeft();
    void rotateRight();
    void render(SDL_Renderer* renderer, size_t centerX, size_t centerY, size_t cellCount, size_t cellSize);
    std::vector<Coords> getTakenCells();
    bool isValid();
    void checkValid(const std::vector<CellType>& board, size_t cellCount);
};