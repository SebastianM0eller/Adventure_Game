//
// Created by sebastian on 12/12/25.
//

#include "Scene.h"
#include <iostream>
#include <fstream>
#include <filesystem>

// --- Initializer --- //

Scene::Scene(const std::string& filePath)
{
  std::ifstream sceneFile(filePath);

  // Check to see if the file opened successfully
  if (!sceneFile.is_open())
  {
    std::cerr << "Failed to open file: " << filePath << '\n';
    return;
  }
  std::string row;
  // read the file line by line
  while (std::getline(sceneFile, row))
  {
    std::vector<std::unique_ptr<Tile>> tileRow = generateTileRow(row);
    if (!tileRow.empty())
    {
      m_grid.push_back(std::move(tileRow));
    }
  }
}

std::vector<std::unique_ptr<Tile>> Scene::generateTileRow(const std::string& row) const
{
  std::vector<std::unique_ptr<Tile>> tileRow;
  for (char tileKey : row)
  {
    try
    {
      tileRow.push_back(m_tiles.at(tileKey)->clone());
    }
    catch (const std::out_of_range& e)
    {
      tileRow.push_back(m_tiles.at('.')->clone());
    }
  }
  return tileRow;
}

// --- Display --- //

/**
 * @brief Renders the scene to the standard output.
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

// --- Movement --- //

/**
 * @brief Attempts to move the player to a new location within the grid.
 *
 * The function retrieves the movement vector and validates the destination.
 * It handles the movement, including bounds checking, walkability
 * checks, and tile transition events (onExited/onEntered).
 * @note handles the std::out_of_range exception internally.
 */
void Scene::move()
{
  const std::vector<int> move = getMove();
  const int dx = move[0];
  const int dy = move[1];

  // Check if we actually move
  if (dx == 0 && dy == 0) return;

  if (!isMoveValid(dx, dy)) return;

  // Handle the move away from the tile.
  m_playerLocation->onExited();
  std::swap(m_playerLocation, m_grid.at(m_playerY).at(m_playerX));

  // Move the player to the new tile and handle the entered logic
  m_playerX += dx;
  m_playerY += dy;

  std::swap(m_playerLocation, m_grid.at(m_playerY).at(m_playerX));
  m_playerLocation->onEntered();
}

/**
 * @brief Asks the player for a direction to move
 * @return Vector 2 containing the move direction [dx, dy]
 */
std::vector<int> Scene::getMove() const
{
  std::cout << "What direction do you want to move? (n/s/e/w)" << "\n";
  std::string direction;
  std::cin >> direction;

  switch (direction[0])
  {
  case 'n':
    return {0, -1};
  case 's':
    return {0, 1};
  case 'e':
    return {1, 0};
  case 'w':
    return {-1, 0};

  default:
    std::cout << "Invalid direction!" << '\n';
    return {0, 0};
  }
}

/**
 *
 * @param dx The distance in the horizontal direction.
 * @param dy The distance in the vertical direction.
 * @return True if the move is valid, false otherwise.
 */
bool Scene::isMoveValid(const int dx, const int dy) const
{
  try
  {
    if (!m_grid.at(m_playerY + dy).at(m_playerX + dx)->isWalkable())
    {
      std::cout << "You cannot move that way!" << '\n';
      return false;
    }
  }
  catch (const std::out_of_range& e)
  {
    std::cout << "You cannot move that way!" << '\n';
    return false;
  }
  return true;
}
