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
#include <functional>


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

  using requestNewScene = std::function<void(bool)>;
  requestNewScene nextScene;

private:
  /**
   * @brief A 2D vector, storing the tiles in the scene.
   * - Layout: [Row][Column]
   * - [0][0] is top-left
   * - [Row] corresponds to Y (vertical)
   * - [Column] corresponds to X (horizontal)
   */
  std::vector<std::vector<std::unique_ptr<Tile>>> m_grid;

  /**
   * @brief An unordered map, containing a char-Tile key-value pair.
   */
  std::unordered_map<char,std::shared_ptr<Tile>> m_tiles {
    {'.', std::make_shared<EmptyTile>(EmptyTile())},
    {'#', std::make_shared<PathTile>(PathTile())}
  };

  /**
 * @brief Points to the tile, the player stands on.
 */
  std::unique_ptr<Tile> m_playerLocation;
  int m_playerX;
  int m_playerY;

  [[nodiscard]] std::vector<std::unique_ptr<Tile>> generateTileRow(const std::string& row) const;

  void printBorder() const;
  void printTiles() const;

  [[nodiscard]] std::vector<int> getMove() const;
  [[nodiscard]] bool isMoveValid(int dx, int dy) const;
};
