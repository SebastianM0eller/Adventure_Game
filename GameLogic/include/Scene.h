//
// Created by sebastian on 12/12/25.
//

#pragma once
#include "Tile.h"
#include <vector>
#include <memory>


/**
 * @class Scene
 * @brief Stores a grid of tiles, which represents parts of the world.
 */
class Scene
{
public:
  Scene();
  //Scene(std::string filePath);
  ~Scene() = default;

  void display() const;

private:
  /**
   * @brief A 2D vector, storing the tiles in the scene.
   * - Layout: [Row][Column]
   * - [0][0] is top-left
   * - [Row] corresponds to Y (vertical)
   * - [Column] corresponds to X (horizontal)
   */
  std::vector<std::vector<std::unique_ptr<Tile>>> m_grid;

  void printBorder() const;
  void printTiles() const;

  std::vector<std::unique_ptr<Tile>> createRow(int width, bool walkable, char c);
};
