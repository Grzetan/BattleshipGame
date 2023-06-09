#include "ship.h"

void Ship::move(const Coords& c){
    origin = c;
}

void Ship::shot(std::vector<CellType>& board, size_t cellCount){
    std::vector<Coords> taken = getTakenCells();
    
    bool alive = false;
    for(auto& cell : taken){
        if(board[cell.y*cellCount+cell.x] != HIT)
            alive = true;
    }

    isAlive = alive;
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

Coords Ship::getOrigin(){
    return origin;
}

void Ship::render(SDL_Renderer* renderer, size_t centerX, size_t centerY, size_t cellCount, size_t cellSize){
    Coords endBlock = origin + direction*(n_blocks-1);
    
    SDL_Rect r;
    r.x = (centerX - cellCount * cellSize / 2) + std::min(origin.x, endBlock.x) * cellSize + 1;
    r.y = (centerY - cellCount * cellSize / 2) + std::min(origin.y, endBlock.y) * cellSize + 1;
    r.w = (centerX - cellCount * cellSize / 2) + std::max(origin.x, endBlock.x) * cellSize - r.x + cellSize;
    r.h = (centerY - cellCount * cellSize / 2) + std::max(origin.y, endBlock.y) * cellSize - r.y + cellSize;

    // std::cout << origin.x << ", " << origin.y << ": " << direction.x << ", " << direction.y << std::endl;


    // Set render color to blue ( rect will be rendered in this color )
    if(isAlive)
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 128 );
    else
        SDL_SetRenderDrawColor( renderer, 128, 0, 0, 128 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
}

std::vector<Coords> Ship::getTakenCells(){
    std::vector<Coords> out;

    for(int i=0; i<n_blocks; i++){
        out.push_back(origin + direction*i);
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

bool Ship::isShipAlive(){
    return isAlive;
}

