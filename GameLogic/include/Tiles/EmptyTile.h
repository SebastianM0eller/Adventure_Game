//
// Created by sebastian on 12/16/25.
//

#pragma once

#include "Tiles/Tile.h"

class EmptyTile : public Tile
{
public:
  EmptyTile();
  ~EmptyTile() override;

  [[nodiscard]] std::unique_ptr<Tile> clone() const override;
};