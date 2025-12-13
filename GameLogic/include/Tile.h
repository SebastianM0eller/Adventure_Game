//
// Created by sebastian on 12/13/25.
//

#pragma once


/**
 * @brief Used to store the data and behavior of a tile.
 *
 */
class Tile
{
public:
  Tile();
  Tile(bool walkable, char character);
  virtual ~Tile() = default;

  [[nodiscard]] char getChar() const;
  [[nodiscard]] bool isWalkable() const;
  virtual void onEntered() {};
  virtual void onExited() {};

private:
  bool m_walkable;
  char m_char;
};