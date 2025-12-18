//
// Created by sebastian on 12/18/25.
//

#pragma once
#include <queue>

#include "Scene.h"

class Game
{
public:
  Game();
  ~Game() = default;

  void Run();
  void addToSceneQueue(int sceneNumber);

private:
  bool m_running;
  std::unique_ptr<Scene> m_scene;
  std::queue<int> m_sceneQueue;

  void assignCallBack();
  bool pollSceneQueue(int& returnValue);
};