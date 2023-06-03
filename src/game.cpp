#include "game.h"

Game::Game(size_t width_, size_t height_, std::vector<size_t> shipSizes) : width(width_), height(height_){
    player1 = new Board(shipSizes, width_*0.25, height_ / 2);
    player2 = new Board(shipSizes, width_*0.75, height_ / 2);

    buttonX1 = width/2 - 150;
    buttonY1 = height - 150;
    buttonX2 = width/2 + 150;
    buttonY2 = height - 150 + 80; 
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

    renderText(renderer, width * 0.25, 120, "Player 1", font, &textTop, &rect);
    renderText(renderer, width * 0.75, 120, "Player 2", font, &textTop, &rect);

    std::string text = (player1Turn) ? "Player 1" : "Player 2";
    text += (!player1Ready || !player2Ready) ? " setup your board" : "";
    renderText(renderer, width / 2, 20, text.c_str(), font, &textTop, &rect);
    player1->render(renderer, player1Turn);
    player2->render(renderer, !player1Turn);

    if(!player1Ready || !player2Ready){
        SDL_Rect r;
        r.x = buttonX1;
        r.y = buttonY1;
        r.w = buttonX2 - buttonX1;
        r.h = buttonY2 - buttonY1;

        Board* player = (player1Turn) ? player1 : player2;

        buttonActive = player->boardValid();

        if(!buttonActive){
            SDL_SetRenderDrawColor(renderer, 128, 0, 0, 128);
        }else{
            SDL_SetRenderDrawColor(renderer, 0, 128, 0, 128);
        }

        // Render rect
        SDL_RenderFillRect(renderer, &r);
        renderText(renderer, width / 2, height-140, "Ready", font, &textTop, &rect);

    }
}

void Game::click(int x, int y){
    // User clicked on the button
    if(x > buttonX1 && x < buttonX2 && y > buttonY1 && y < buttonY2 && buttonActive){
        std::cout << "XD" << std::endl;
        if(player1Turn && !player1Ready){
            player1Turn = false;
            player1Ready = true;
        }else if(!player1Turn && !player2Ready){
            player1Turn = true;
            player2Ready = true;
        }
    }
}


