#pragma once

#include <iostream>

/**
 * @brief Represents the coordinates of a point.
 */
struct Coords {
    int x; ///< The x-coordinate of the point.
    int y; ///< The y-coordinate of the point.

    /**
     * @brief Constructs a Coords object with the specified coordinates.
     *
     * @param x_ The x-coordinate.
     * @param y_ The y-coordinate.
     */
    Coords(int x_, int y_): x(x_), y(y_){};

    /**
     * @brief Checks if the current Coords object is equal to another Coords object.
     *
     * @param c The Coords object to compare with.
     * @return True if the Coords objects are equal, false otherwise.
     */
    bool operator==(const Coords& c);

    /**
     * @brief Checks if the current Coords object is equal to an integer value.
     *
     * @param p The integer value to compare with.
     * @return True if the Coords object is equal to the integer value, false otherwise.
     */
    bool operator==(int p);

    /**
     * @brief Adds the specified Coords object to the current Coords object.
     *
     * @param c The Coords object to add.
     * @return The resulting Coords object after addition.
     */
    Coords operator+=(const Coords& c);

    /**
     * @brief Adds the specified Coords object to the current Coords object.
     *
     * @param c The Coords object to add.
     * @return The resulting Coords object after addition.
     */
    Coords operator+(const Coords& c);

    /**
     * @brief Subtracts the specified Coords object from the current Coords object.
     *
     * @param c The Coords object to subtract.
     * @return The resulting Coords object after subtraction.
     */
    Coords operator-(const Coords& c);

    /**
     * @brief Multiplies the current Coords object by the specified integer value.
     *
     * @param p The integer value to multiply by.
     * @return The resulting Coords object after multiplication.
     */
    Coords operator*=(int p);

    /**
     * @brief Multiplies the current Coords object by the specified integer value.
     *
     * @param p The integer value to multiply by.
     * @return The resulting Coords object after multiplication.
     */
    Coords operator*(int p);

    /**
     * @brief Increments the coordinates of the current Coords object based on the specified cell count.
     *
     * @param cellCount The number of cells.
     */
    void increment(size_t cellCount);

    /**
     * @brief Checks if the current Coords object is empty (both x and y coordinates are zero).
     *
     * @return True if the Coords object is empty, false otherwise.
     */
    bool empty();
};

/**
 * @brief Represents the type of a cell on the board.
 */
enum CellType {
    EMPTY,     ///< Empty cell.
    SHIP,      ///< Cell containing a ship.
    HIT_SHIP,  ///< Cell containing a hit ship.
    HIT        ///< Cell that has been hit but doesn't contain a ship.
};