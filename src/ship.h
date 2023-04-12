#pragma once
#include <iostream>
#include "board.h"

const Coords up {0, 1};
const Coords down {0, -1};
const Coords left {-1, 0};
const Coords right {1, 0};
const std::vector<Coords> cycle {up, right, down, left};

struct Coords{
    int x;
    int y;

    Coords(int x_, int y_) : x(x_), y(y_){};
};

class Ship{
    const size_t n_blocks;
    bool is_alive;
    Coords origin;
    Coords direction;
    bool is_valid;
    bool is_on_board;
    std::vector<size_t> hits;
public:
    Ship(size_t size) : n_blocks(size), 
                        is_alive(true),
                        origin({0, 0}),
                        direction(up),
                        is_valid(true),
                        is_on_board(false){};

    void move(const Coords& c);
    void shot(const Coords& c);
    void rotateLeft();
    void rotateRight();
};