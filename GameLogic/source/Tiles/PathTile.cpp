//
// Created by sebastian on 12/16/25.
//

#include "Tiles/PathTile.h"

PathTile::PathTile()
  : Tile(true, '#') {}

std::unique_ptr<Tile> PathTile::clone() const
{ return std::make_unique<PathTile>(*this); }


