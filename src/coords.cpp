#include "coords.h"

bool Coords::operator==(Coords const& c){
    return x == c.x && y == c.y;
}

Coords Coords::operator+=(const Coords& c){
    return {x + c.x, y + c.y};
}

Coords Coords::operator+(const Coords& c){
    return {x + c.x, y + c.y};
}

Coords Coords::operator*=(int p){
    return {x * p, y * p};
}

Coords Coords::operator*(int p){
    return {x * p, y * p};
}

void Coords::increment(size_t cellCount){
    if(x == cellCount - 1 && y == cellCount - 1){
        x = 0;
        y = 0;
    }else if(x == cellCount - 1){
        x = 0;
        y++;
    }else{
        x++;
    }

}
