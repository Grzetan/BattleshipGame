#include "game.h"

Game::Game(size_t width_, size_t height_, std::vector<size_t> shipSizes) : width(width_), height(height_){
    player1 = new Board(shipSizes, width_*0.25, height_ / 2);
    player2 = new Board(shipSizes, width_*0.75, height_ / 2);
}

void Game::renderText(SDL_Renderer *renderer, 
                      int x, int y, const char *text,
                      TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x - text_width / 2;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;

    SDL_RenderCopy(renderer, *texture, NULL, rect);
}

void Game::renderFrame(SDL_Renderer* renderer){
    SDL_Texture *textTop;
    SDL_Rect rect;

    const char* text = (player1Turn) ? "Player 1" : "Player 2";
    renderText(renderer, width / 2, 20, text, font, &textTop, &rect);
    // std::cout << "===================" << std::endl;
    player1->render(renderer, player1Turn);
    player2->render(renderer, !player1Turn);
}

