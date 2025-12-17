//
// Created by sebastian on 12/16/25.
//

#pragma once
#include "Tile.h"

class PathTile : public Tile
{
  public:
    PathTile();
    ~PathTile() override = default;

  [[nodiscard]] std::unique_ptr<Tile> clone() const override;
};