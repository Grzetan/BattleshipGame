#include "ship.h"

void Ship::move(const Coords& c){
    origin = c;
}

void Ship::shot(const Coords& c){
    Coords currentCell = origin;
    for(int i=0; i<n_blocks; i++){
        // If shot cell is part of a ship and this part of a ship wasn't already hit
        if(currentCell == c && std::find(hits.begin(), hits.end(), i) == hits.end())
            hits.push_back(i);

        currentCell += direction;
    }
}

void Ship::rotateRight(){
    if(direction == up)
        direction = right;
    else if(direction == right)
        direction = down;
    else if(direction == down)
        direction = left;
    else if(direction == left)
        direction = up;
}

void Ship::rotateLeft(){
    if(direction == up)
        direction = left;
    else if(direction == left)
        direction = down;
    else if(direction == down)
        direction = right;
    else if(direction == right)
        direction = up;
}

void Ship::render(SDL_Renderer* renderer, size_t centerX, size_t centerY, size_t cellCount, size_t cellSize){
    SDL_Rect r;
    r.x = (centerX - cellCount * cellSize / 2) + origin.x * cellSize;
    r.y = (centerY - cellCount * cellSize / 2) + (origin.y) * cellSize;
    r.w = cellSize;
    r.h = cellSize*n_blocks;

    // std::cout << origin.x << ", " << origin.y << std::endl;


    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 128 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
}

std::vector<Coords> Ship::getTakenCells(){
    std::vector<Coords> out;

    Coords offset = direction;
    for(int i=0; i<n_blocks; i++){
        out.push_back(origin + offset*i);
    }

    return out;
}

bool Ship::isValid(){
    return valid;
}

void Ship::checkValid(const std::vector<CellType>& board, size_t cellCount){
    std::vector<Coords> taken = getTakenCells();
    bool valid_ = true;

    for(auto& cell : taken){
        if(!valid_) break;

        // Check collision with other ships
        for(auto& c : fieldsToCheck){
            Coords curr = cell + c;
            if(curr.x < 0 || curr.x >= cellCount || curr.y < 0 || curr.y >= cellCount) continue;
            if(board[curr.y*cellCount + curr.x] != EMPTY){
                valid_ = false;
                break;
            }
        }

        // Check if ship is on the board
        if(cell.x < 0 || cell.y < 0 || cell.x > cellCount-1 || cell.y > cellCount-1){
            valid_ = false;
            break;
        }
    }

    valid = valid_;
}
