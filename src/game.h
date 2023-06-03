#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "board.h"

class Game{
    const size_t width, height;
    std::vector<size_t> shipSizes;
    int player1Turn = true;
    Board* player1, *player2;

    TTF_Font* font = TTF_OpenFont("./fonts/VertigoFLF.ttf", 50);
    void renderText(SDL_Renderer *renderer, 
                           int x, 
                           int y, 
                           const char *text, 
                           TTF_Font *font, 
                           SDL_Texture **texture, 
                           SDL_Rect *rect);


public:
    Game(size_t width_, size_t height_, std::vector<size_t> shipSizes);

    void renderFrame(SDL_Renderer* renderer);

};