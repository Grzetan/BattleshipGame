#include "board.h"

Board::Board() : centerX(0), centerY(0){
    
}

Board::Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_) : centerX(centerX_), centerY(centerY_){
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

void Board::render(SDL_Renderer* renderer, bool visible){
    size_t boardSize = cellSize * cellCount;

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    for(int i=0; i<=cellCount; i++){
        SDL_RenderDrawLine(renderer, 
                           centerX - boardSize / 2, 
                           centerY - boardSize / 2 + i * cellSize, 
                           centerX + boardSize / 2, 
                           centerY - boardSize / 2 + i * cellSize);
        
        SDL_RenderDrawLine(renderer, 
                    centerX - boardSize / 2 + i * cellSize,
                    centerY - boardSize / 2,
                    centerX - boardSize / 2 + i * cellSize,
                    centerY + boardSize / 2);
    }

    if(visible){
        for(auto& ship : ships){
            ship.render(renderer);
        }
    }else{

    }

}

