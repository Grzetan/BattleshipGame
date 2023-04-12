#include "game.h"

Game::Game(size_t width_, size_t height_, std::vector<size_t> shipSizes) : width(width_), height(height_){
    player1 = Board(shipSizes);
    player2 = Board(shipSizes);
}
