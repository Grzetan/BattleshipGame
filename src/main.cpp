#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <vector>
#include <algorithm>

#define W 1000
#define H 800

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, const char *text,
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
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}


int main(int argc, char *argv[]){
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

    int close = 0;
    int x,y; // For mouse coordinates
    srand(time(NULL));

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont("./fonts/VertigoFLF.ttf", 50);

    SDL_Texture *texture1;
    SDL_Rect rect;

    get_text_and_rect(renderer, 200, 200, "Hello World", font, &texture1, &rect);

    while (!close) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect r;
        r.x = 50;
        r.y = 50;
        r.w = 50;
        r.h = 50;

        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

        SDL_RenderFillRect( renderer, &r );

        SDL_RenderCopy(renderer, texture1, NULL, &rect);

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