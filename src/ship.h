#pragma once

#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "coords.h"

const Coords up {0, 1};
const Coords down {0, -1};
const Coords left {-1, 0};
const Coords right {1, 0};

const std::vector<Coords> fieldsToCheck = { {-1,  1}, {0,  1}, {1,  1},
                                            {-1,  0}, {0,  0}, {1,  0},
                                            {-1, -1}, {0, -1}, {1, -1} };

/**
 * @brief Represents a ship in the game.
 */
class Ship {
    const size_t n_blocks; ///< The number of blocks (size) of the ship.
    bool isAlive; ///< Determines whether the ship is alive.
    Coords origin; ///< The origin coordinates of the ship.
    Coords direction; ///< The direction of the ship.
    bool valid; ///< Determines whether the ship is valid (placement is valid).

public:
    /**
     * @brief Constructor for the Ship class.
     *
     * @param size The number of blocks (size) of the ship.
     */
    Ship(size_t size) : n_blocks(size), 
                    isAlive(true),
                    origin({0, 0}),
                    direction(up),
                    valid(false){};

    /**
     * @brief Moves the ship by the specified coordinates.
     *
     * @param c The coordinates to move the ship by.
     */
    void move(const Coords& c);

    /**
     * @brief Handles a shot on the ship, updating its status.
     *
     * @param board The board representing the game state.
     * @param cellCount The number of cells in the board.
     */
    void shot(std::vector<CellType>& board, size_t cellCount);

    /**
     * @brief Rotates the ship to the left.
     */
    void rotateLeft();

    /**
     * @brief Rotates the ship to the right.
     */
    void rotateRight();

    /**
     * @brief Retrieves the origin coordinates of the ship.
     *
     * @return The origin coordinates of the ship.
     */
    Coords getOrigin();

    /**
     * @brief Renders the ship on the specified SDL renderer.
     *
     * @param renderer The SDL renderer to render the ship on.
     * @param centerX The x-coordinate of the ship's center.
     * @param centerY The y-coordinate of the ship's center.
     * @param cellCount The number of cells in the board.
     * @param cellSize The size of each cell in pixels.
     */
    void render(SDL_Renderer* renderer, size_t centerX, size_t centerY, size_t cellCount, size_t cellSize);

    /**
     * @brief Retrieves the coordinates occupied by the ship.
     *
     * @return A vector of coordinates occupied by the ship.
     */
    std::vector<Coords> getTakenCells();

    /**
     * @brief Checks if the ship is valid (placement is valid) on the specified board.
     *
     * @return True if the ship is valid, false otherwise.
     */
    bool isValid();

    /**
     * @brief Checks if the ship is valid (placement is valid) on the specified board.
     *
     * @param board The board representing the game state.
     * @param cellCount The number of cells in the board.
     */
    void checkValid(const std::vector<CellType>& board, size_t cellCount);

    /**
     * @brief Checks if the ship is alive.
     *
     * @return True if the ship is alive, false otherwise.
     */
    bool isShipAlive();
};