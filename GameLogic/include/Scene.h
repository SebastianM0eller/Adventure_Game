//
// Created by sebastian on 12/12/25.
//

#pragma once
#include "Tiles/Tile.h"
#include "Tiles/EmptyTile.h"
#include "Tiles/PathTile.h"
#include <vector>
#include <memory>
#include <unordered_map>


/**
 * @class Scene
 * @brief Stores a grid of tiles, which represents parts of the world.
 */
class Scene
{
public:
  Scene(const std::string& filePath);
  ~Scene() = default;

  void display() const;
  void move();

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

  /**
   * @brief Points to the tile, the player stands on.
   */
  std::unique_ptr<Tile> m_playerLocation;
  int m_playerX {0};
  int m_playerY {2};

  [[nodiscard]] std::vector<int> getMove() const;

  std::unordered_map<char,std::shared_ptr<Tile>> m_tiles {
  {' ', std::make_shared<EmptyTile>(EmptyTile())},
  {'#', std::make_shared<PathTile>(PathTile())}
  };
};
