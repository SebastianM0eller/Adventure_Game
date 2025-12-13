//
// Created by sebastian on 12/12/25.
//

#include "Scene.h"

#include <iostream>
#include <fstream>
#include <filesystem>

/**
 * @brief Constructs a new scene object.
 * Initializes the internal tile grid, with a default size
 * of 5x20 The layout consists of empty rows, with a single
 * path running horizontally across the center.
 */
Scene::Scene()
{
  m_grid.push_back(createRow(20, false, ' '));
  m_grid.push_back(createRow(20, false, ' '));
  m_grid.push_back(createRow(20, true, '#'));
  m_grid.push_back(createRow(20, false, ' '));
  m_grid.push_back(createRow(20, false, ' '));
}

/**
 * @brief Renders the current scene state to the standard output.
 * @details This includes a border and the internal grid of tiles.
 */
void Scene::display() const
{
  if (m_grid.empty()) return; // Safety check

  printBorder();
  printTiles();
  printBorder();
}

/**
 * @brief Prints a horizontal border, matching the width of the grid.
 * Uses dashed ('-') to represent the boundary.
 */
void Scene::printBorder() const
{
  // The loop is used to match the tile width
  for (const auto& _ : m_grid[0])
  {
    std::cout << '-';
  }

  // Adds some additional padding to match the vertical border.
  std::cout << "-- \n";
}


/**
 * @brief Iterates through the tile grid and prints the corresponding chars.
 * Uses ('|') at the start and end of each row, for a clean boundary.
 */
void Scene::printTiles() const
{
  for (const auto& row : m_grid)
  {
    std::cout << '|';
    for (const auto& tile : row)
    {
      std::cout << tile->getChar();
    }
    std::cout << "| \n";
  }
}

/**
 * @brief Generates a row of distinct tile objects.
 * * @param width Number og tiles to generate
 * @param walkable The collision state for all the tiles in the row.
 * @param c The ASCII char representation for all the tiles in the row.
 * @return A vector of unique_ptrs to the tiles.
 */
std::vector<std::unique_ptr<Tile>> Scene::createRow(const int width, const bool walkable, const char c)
{
  std::vector<std::unique_ptr<Tile>> row;
  for (int i = 0; i < width; ++i)
  {
    row.push_back(std::make_unique<Tile>(walkable, c));
  }

  return row;
}
