#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <time.h>
#include <vector>
#include <algorithm>

#define W 500
#define H 500

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

    SDL_Surface* background = SDL_GetWindowSurface(win);

    int close = 0;
    int x,y; // For mouse coordinates
    srand(time(NULL));

    while (!close) {

        SDL_UpdateWindowSurface(win);

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