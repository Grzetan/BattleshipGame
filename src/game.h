#pragma once
#include <SDL2/SDL.h>
#include "board.h"

class Game{
    size_t width, height;
    std::vector<size_t> shipSizes;
    Board player1, player2;

    Game(size_t width_, 
         size_t height_, 
         std::vector<size_t> shipSizes_) : 
         width(width_), 
         height(height_),
         shipSizes(shipSizes_){    
        player1 = Board(shipSizes);
        player2 = Board(shipSizes);
    }
};