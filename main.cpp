//
// Created by sebastian on 12/12/25.
//

#include <iostream>
#include <ostream>

#include "Scene.h"

int main()
{

  Scene world;
  while (true)
  {
    world.move();
    world.display();
  }
}