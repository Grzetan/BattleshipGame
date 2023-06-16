#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "board.h"

/**
 * @brief Represents a game instance.
 */
class Game {
    const size_t width; ///< The width of the game window.
    const size_t height; ///< The height of the game window.
    std::vector<size_t> shipSizes; ///< The sizes of the ships used in the game.
    bool player1Turn = true; ///< Determines whether it is player 1's turn.
    bool player1Ready = false; ///< Determines whether player 1 is ready to start the game.
    bool player2Ready = false; ///< Determines whether player 2 is ready to start the game.
    bool restartGame = false; ///< Determines whether a game restart is requested.
    Board* player1; ///< Pointer to player 1's board.
    Board* player2; ///< Pointer to player 2's board.

    size_t buttonX1, buttonY1, buttonX2, buttonY2; ///< Button coordinates.

    TTF_Font* font = TTF_OpenFont("./fonts/VertigoFLF.ttf", 50); ///< The font used for rendering text.

    /**
     * @brief Renders text on the specified renderer.
     *
     * @param renderer The SDL renderer to render the text on.
     * @param x The x-coordinate of the text.
     * @param y The y-coordinate of the text.
     * @param text The text to render.
     * @param font The font used for rendering.
     * @param texture Pointer to the SDL texture used for rendering.
     * @param rect The SDL rectangle specifying the dimensions of the rendered text.
     */
    void renderText(SDL_Renderer* renderer, int x, int y, const char* text, TTF_Font* font, SDL_Texture** texture, SDL_Rect* rect);

public:
    /**
     * @brief Constructor for the Game class.
     *
     * @param width_ The width of the game window.
     * @param height_ The height of the game window.
     * @param shipSizes The sizes of the ships used in the game.
     */
    Game(size_t width_, size_t height_, std::vector<size_t> shipSizes);

    /**
     * @brief Renders a frame of the game on the specified SDL renderer.
     *
     * @param renderer The SDL renderer to render the game on.
     */
    void renderFrame(SDL_Renderer* renderer);

    /**
     * @brief Handles a click event at the specified coordinates.
     *
     * @param x The x-coordinate of the click event.
     * @param y The y-coordinate of the click event.
     */
    void click(int x, int y);

    /**
     * @brief Handles a mouse move event at the specified coordinates.
     *
     * @param x The x-coordinate of the mouse move event.
     * @param y The y-coordinate of the mouse move event.
     */
    void mouseMove(int x, int y);

    /**
     * @brief Handles a mouse up event.
     */
    void mouseup();
};