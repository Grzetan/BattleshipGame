#include "board.h"

Board::Board() : centerX(0), centerY(0){
    
}

Board::Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_) : centerX(centerX_), centerY(centerY_){
    board.reserve(CELL_COUNT*CELL_COUNT);
    for(int i=0; i<CELL_COUNT*CELL_COUNT; i++){
        board.push_back(EMPTY);    
    }
    
    ships.reserve(shipSizes.size());
    for(int i=0; i<shipSizes.size(); i++){
        Ship* ship = new Ship(shipSizes[i]);

        size_t startX = (size_t)((float)std::rand() / (float)RAND_MAX * cellCount);
        size_t startY = (size_t)((float)std::rand() / (float)RAND_MAX * cellCount);
        size_t startRotation = (size_t)((float)std::rand() / (float)RAND_MAX * 4);
        for(int k=0; k<startRotation; k++){
            ship->rotateLeft();
        }

        Coords current(startX, startY);
        int j=0;

        while(!ship->isValid() && j++<cellCount*cellCount*4){
            // Either rotate or move the ship
            if(j%4 == startRotation){
                current.increment(cellCount);
            }else{
                ship->rotateLeft();
            }

            ship->move(current);

            ship->checkValid(board, cellCount);
        }

        if(j >= cellCount*cellCount*4){
            throw std::runtime_error("Board is too small for ships");
        }

        // Place ship on board
        for(auto& c : ship->getTakenCells()){
            board[c.y*cellCount+c.x] = SHIP;
        }

        ships.push_back(ship);
    }
}

void Board::shot(const Coords& c){
    for(auto& ship : ships)
        ship->shot(c);

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
            ship->render(renderer, centerX, centerY, cellCount, cellSize);
        }
    }

}

bool Board::boardValid(){
    for(auto& ship : ships){
        if(!ship->isValid()) return false;
    }

    return true;
}

