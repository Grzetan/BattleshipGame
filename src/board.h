#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <SDL2/SDL.h>
#include "ship.h"

#define CELL_COUNT 10

/**
 * @brief Represents a game board for a battleship-like game.
 */
class Board {
    static const size_t cellCount = CELL_COUNT; ///< The number of cells in each dimension of the board.
    static const size_t cellSize = 40; ///< The size (in pixels) of each cell on the board.
    const size_t centerX, centerY; ///< The center coordinates of the board.

    std::vector<Ship*> ships; ///< The ships placed on the board.
    std::vector<Coords> hits; ///< The coordinates of the successful hits on the board.
    std::vector<CellType> board; ///< The state of each cell on the board.
    int selectedShip = -1; ///< The index of the currently selected ship.

    /**
     * @brief Sets up the ships on the board.
     *
     * @param shipSizes The sizes of the ships to be placed on the board.
     */
    void setupShips(std::vector<size_t>& shipSizes);

public:
    /**
     * @brief Default constructor for the Board class.
     */
    Board();

    /**
     * @brief Constructor for the Board class.
     *
     * @param shipSizes The sizes of the ships to be placed on the board.
     * @param centerX_ The x-coordinate of the center of the board.
     * @param centerY_ The y-coordinate of the center of the board.
     */
    Board(std::vector<size_t>& shipSizes, size_t centerX_, size_t centerY_);

    /**
     * @brief Processes a shot fired at the specified coordinates on the board.
     *
     * @param x The x-coordinate of the shot.
     * @param y The y-coordinate of the shot.
     * @return True if the shot was successful (hit a ship), false otherwise.
     */
    bool shot(int x, int y);

    /**
     * @brief Renders the board on the specified SDL renderer.
     *
     * @param renderer The SDL renderer to render the board on.
     * @param visible Determines whether ships should be visible on the board.
     */
    void render(SDL_Renderer* renderer, bool visible);

    /**
     * @brief Checks if the board is valid (i.e., all ships are placed within the bounds and do not overlap).
     *
     * @return True if the board is valid, false otherwise.
     */
    bool boardValid();

    /**
     * @brief Retrieves the coordinates of the clicked cell on the board based on the specified screen coordinates.
     *
     * @param x The x-coordinate of the click on the screen.
     * @param y The y-coordinate of the click on the screen.
     * @return The coordinates of the clicked cell.
     */
    Coords getClickedCell(int x, int y);

    /**
     * @brief Selects a ship on the board based on the specified screen coordinates.
     *
     * @param x The x-coordinate of the click on the screen.
     * @param y The y-coordinate of the click on the screen.
     */
    void selectShip(int x, int y);

    /**
     * @brief Handles the mouseup event on the board.
     */
    void mouseup();

    /**
     * @brief Handles the mousemove event on the board.
     *
     * @param x The x-coordinate of the mouse position.
     * @param y The y-coordinate of the mouse position.
     */
    void mousemove(int x, int y);
    
    /**
     * @brief Resets the board by removing all ships and repositioning them based on the specified ship sizes.
     *
     * @param shipSizes The sizes of the ships to be placed on the board.
     */
    void resetBoard(std::vector<size_t>& shipSizes);

    /**
     * @brief Checks if the game is over (i.e., all ships have been sunk).
     *
     * @return True if the game is over, false otherwise.
     */
    bool isGameOver();
};