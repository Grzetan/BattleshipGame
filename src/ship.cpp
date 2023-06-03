#include "ship.h"

bool Coords::operator==(const Coords& c){
    return x == c.x && y == c.y;
}

Coords Coords::operator+=(const Coords& c){
    return {x + c.x, y + c.y};
}

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

void Ship::render(SDL_Renderer* renderer){
    SDL_Rect r;
    r.x = origin.x;
    r.y = origin.y;
    r.w = 50;
    r.h = 500;

    // Set render color to blue ( rect will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

    // Render rect
    SDL_RenderFillRect( renderer, &r );
}
