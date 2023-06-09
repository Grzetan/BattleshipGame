#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "board.h"

class Game{
    const size_t width, height;
    std::vector<size_t> shipSizes;
    bool player1Turn = true;
    bool player1Ready = false;
    bool player2Ready = false;
    bool restartGame = false;
    Board* player1, *player2;

    size_t buttonX1, buttonY1, buttonX2, buttonY2;

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

    void click(int x, int y);

    void mouseMove(int x, int y);

    void mouseup();
};