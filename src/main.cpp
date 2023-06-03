#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include "game.h"

#define W 1200
#define H 800

int main(int argc, char *argv[]){
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    TTF_Init();
    SDL_Window* win = SDL_CreateWindow("Battleships game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       W,
                                       H,
                                       SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // SDL_Texture *texture1;
    // SDL_Rect rect;

    // get_text_and_rect(renderer, 200, 200, "Hello World", font, &texture1, &rect);

    Game game(W, H, {1,1,1,1});
    bool close = false;

    while (!close) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // SDL_RenderCopy(renderer, texture1, NULL, &rect);
        game.renderFrame(renderer);

        SDL_RenderPresent(renderer);

        // Events handling
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
            }
            // SDL_GetMouseState(&x,&y);
            // if(event.button.button == SDL_BUTTON_LEFT){

            // }
            // if(event.button.button == SDL_BUTTON_RIGHT){

            // }
        }
        SDL_Delay(1000 / 60);
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
 
    return 0;
}