//
// Created by sebastian on 12/12/25.
//

#pragma once
#include "Tile.h"
#include <string>
#include <vector>


/**
 * @class MapScene
 * @brief Stores a grid of tiles, which represents parts of the world.
 */
class MapScene
{
public:
  MapScene();
  //MapScene(std::string filePath);
  ~MapScene() = default;

  void display() const;

private:
  /**
   * @brief A 2D vector, storing the tiles in the scene.
   * - Layout: [Row][Column]
   * - [0][0] is top-left
   * - [Row] corresponds to Y (vertical)
   * - [Column] corresponds to X (horizontal)
   */
  std::vector<std::vector<Tile>> m_grid;

  void printBorder() const;
  void printTiles() const;
};
