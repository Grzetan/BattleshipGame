#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <vector>
#include <algorithm>

#define W 1000
#define H 800

void renderText(){

}

int main(int argc, char *argv[]){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("Battleships game",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       W,
                                       H,
                                       SDL_WINDOW_SHOWN);

    int close = 0;
    int x,y; // For mouse coordinates
    srand(time(NULL));

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    while (!close) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_Rect r;
        r.x = 50;
        r.y = 50;
        r.w = 50;
        r.h = 50;

        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

        SDL_RenderFillRect( renderer, &r );

        SDL_RenderPresent(renderer);

        // Events handling
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
            }
            SDL_GetMouseState(&x,&y);
            if(event.button.button == SDL_BUTTON_LEFT){

            }
            if(event.button.button == SDL_BUTTON_RIGHT){

            }
        }
        SDL_Delay(1000 / 60);
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
 
    return 0;
}