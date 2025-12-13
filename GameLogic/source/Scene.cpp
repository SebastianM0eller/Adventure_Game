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
MapScene::MapScene()
{
  const std::vector<Tile> row_empty(20, Tile());
  const std::vector<Tile> row_with_path(20, Tile(true, '#'));

  m_grid.push_back(row_empty);
  m_grid.push_back(row_empty);
  m_grid.push_back(row_with_path);
  m_grid.push_back(row_empty);
  m_grid.push_back(row_empty);
}

/*
Scene::Scene(std::string filePath)
{
  std::ifstream inputFile(filePath);

  // Check if the file was opened successfully
  if (!inputFile.is_open())
  {
    std::cerr << "Error: Could not open the specified file" << std::endl;
  }

  std::string line;
  while (std::getline(inputFile, line))
  {
    std::vector<Tile> row;
    for (char c : line)
    {
      row.push_back(static_cast<Tile>(c));
    }
    m_tiles.push_back(row);
  }
}
*/

/**
 * @brief Renders the current scene state to the standard output.
 * @details This includes a border and the internal grid of tiles.
 */
void MapScene::display() const
{
  if (m_grid.empty()) return; // Safety check

  printBorder();
  printTiles();
  printBorder();
}

/**
 * @brief Prints a horizontal border, matching the width the grid.
 * Uses dashed ('-') to represent the boundary.
 */
void MapScene::printBorder() const
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
void MapScene::printTiles() const
{
  for (const auto& row : m_grid)
  {
    std::cout << '|';
    for (const auto& tile : row)
    {
      std::cout << tile.getChar();
    }
    std::cout << "| \n";
  }
}
