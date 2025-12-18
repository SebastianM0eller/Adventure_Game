//
// Created by sebastian on 12/16/25.
//

#include "Tiles/EmptyTile.h"

EmptyTile::EmptyTile()
  : Tile(false, ' ') {}

EmptyTile::~EmptyTile() {}

std::unique_ptr<Tile> EmptyTile::clone() const
{ return std::make_unique<EmptyTile>(*this); }
