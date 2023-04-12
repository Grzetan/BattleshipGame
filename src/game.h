#pragma once
#include <SDL2/SDL.h>
#include "board.h"

class Game{
    const size_t width, height;
    std::vector<size_t> shipSizes;
    Board player1, player2;
public:
    Game(size_t width_, size_t height_, std::vector<size_t> shipSizes);


};