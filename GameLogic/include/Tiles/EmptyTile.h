//
// Created by sebastian on 12/16/25.
//

#pragma once

#include "Tile.h"

class EmptyTile : public Tile
{
public:
  EmptyTile();
  ~EmptyTile() override = default;

  std::unique_ptr<Tile> clone() const override;
};