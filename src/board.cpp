#include "board.h"

Board::Board() : centerX(0), centerY(0){
    
}

Board::Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_) : centerX(centerX_), centerY(centerY_){
    board.reserve(CELL_COUNT*CELL_COUNT);
    for(int i=0; i<CELL_COUNT*CELL_COUNT; i++){
        board.push_back(EMPTY);    
    }
    
    setupShips(shipSizes);
}

void Board::setupShips(std::vector<size_t>& shipSizes){
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

bool Board::shot(int x, int y){
    Coords c = getClickedCell(x, y);

    if(c == -1 || board[c.y*cellCount + c.x] == HIT) return false;

    board[c.y*cellCount + c.x] = HIT;

    for(auto& ship : ships)
        ship->shot(board, cellCount);

    return true;
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

    SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

    for(int x=0; x<cellCount; x++){
        for(int y=0; y<cellCount; y++){
            if(board[y*cellCount + x] == HIT){
                SDL_RenderDrawLine(renderer, 
                                    centerX - boardSize / 2 + x * cellSize, 
                                    centerY - boardSize / 2 + y * cellSize,
                                    centerX - boardSize / 2 + (x+1) * cellSize,  
                                    centerY - boardSize / 2 + (y+1) * cellSize);
                SDL_RenderDrawLine(renderer, 
                                    centerX - boardSize / 2 + x * cellSize, 
                                    centerY - boardSize / 2 + (y+1) * cellSize,
                                    centerX - boardSize / 2 + (x+1) * cellSize, 
                                    centerY - boardSize / 2 + y * cellSize);
 
            }
        }
    }
}

bool Board::boardValid(){
    for(auto& ship : ships){
        if(!ship->isValid()) return false;
    }

    return true;
}

Coords Board::getClickedCell(int x, int y){
    int relX = x - (centerX - cellCount * cellSize / 2);
    int relY = y - (centerY - cellCount * cellSize / 2);

    if(relX < 0 || relY < 0 || relX > cellCount * cellSize || relY > cellCount * cellSize)
        return {-1, -1};


    return {relX / (int)cellSize, relY / (int)cellSize};
}

void Board::selectShip(int x, int y){
    Coords cell = getClickedCell(x, y);
    if(cell == -1) return;

    for(int i=0; i<ships.size(); i++){
        for(auto& c : ships[i]->getTakenCells()){
            if(c == cell){
                selectedShip = i;
                break;
            }
        }
    }
}

void Board::mouseup(){
    selectedShip = -1;
}

void Board::mousemove(int x, int y){
    if(selectedShip == -1) return;
    Coords cell = getClickedCell(x, y);

    Coords startingPos = ships[selectedShip]->getOrigin();

    Coords offset = cell - startingPos;

    // Temporarly remove ship from board
    for(auto& c : ships[selectedShip]->getTakenCells()){
        board[c.y * cellCount + c.x] = EMPTY;
    }

    // Move X
    ships[selectedShip]->move({startingPos.x + offset.x, startingPos.y});
    ships[selectedShip]->checkValid(board, cellCount);
    if(!ships[selectedShip]->isValid()){
        ships[selectedShip]->move(startingPos);
    }

    startingPos = ships[selectedShip]->getOrigin();

    // Move Y
    ships[selectedShip]->move({startingPos.x, startingPos.y + offset.y});
    ships[selectedShip]->checkValid(board, cellCount);
    if(!ships[selectedShip]->isValid()){
        ships[selectedShip]->move(startingPos);
        ships[selectedShip]->checkValid(board, cellCount);
    }

    // Place ship back on board
    for(auto& c : ships[selectedShip]->getTakenCells()){
        board[c.y * cellCount + c.x] = SHIP;
    }
}

void Board::resetBoard(std::vector<size_t>& shipSizes){
    ships = {};

    for(int i=0; i<CELL_COUNT*CELL_COUNT; i++){
        board[i] = EMPTY;    
    }

    setupShips(shipSizes);
}

bool Board::isGameOver(){
    for(auto& ship : ships){
        if(ship->isShipAlive()) return false;
    }

    return true;
}