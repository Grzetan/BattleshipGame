#include "board.h"

Board::Board(){
    
}

Board::Board(std::vector<size_t>& shipSizes){
    ships.reserve(shipSizes.size());
    for(const auto& size : shipSizes)
        ships.push_back(Ship(size));
}

void Board::shot(const Coords& c){
    for(auto& ship : ships)
        ship.shot(c);

    hits.push_back(c);
}
