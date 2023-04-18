#include "board.h"

Board::Board(){
    
}

Board::Board(std::vector<size_t>& shipSizes){
    ships.reserve(shipSizes.size());
    for(int i=0; i<shipSizes.size(); i++){
        ships.push_back(Ship(shipSizes[i]));
        shipsInStorage.push_back(i);
    }
}

void Board::shot(const Coords& c){
    for(auto& ship : ships)
        ship.shot(c);

    hits.push_back(c);
}
