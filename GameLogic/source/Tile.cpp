//
// Created by sebastian on 12/13/25.
//

#include "Tile.h"

/**
 * @brief Constructs a default tile.
 * * Initializes the tile as "empty space" (non-walkable and invisible).
 * Default ASCII char is a space (' ')
 */
Tile::Tile()
  : m_walkable(false), m_char(' ') {}


/**
 * @brief Constructs a tile with specific properties.
 * * Sets the initial state of the tile for rendering and collision.
 * @param walkable If true, players can move onto the tile.
 * @param character The ASCII char used to render the tile.
 */
Tile::Tile(const bool walkable, const char character)
  : m_walkable(walkable), m_char(character) {}

/**
 * @brief Return the ASCII char used to render the tile.
 */
char Tile::getChar() const { return m_char; }

/**
 * @brief Checks if the tile is walkable.
 * @return True if the tile is walkable, false otherwise.
 */
bool Tile::isWalkable() const { return m_walkable; }