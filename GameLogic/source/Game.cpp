//
// Created by sebastian on 12/18/25.
//

#include "Game.h"

#include <iostream>

Game::Game()
{
  return;
}

void Game::Run()
{
  while (m_running)
  {
    m_scene->display();
    m_scene->move();

    if (int sceneNumber; pollSceneQueue(sceneNumber))
    {
      // Initialize a new scene and set it as the current scene (m_scene)
      assignCallBack();
    }
  }
}

void Game::addToSceneQueue(const int sceneNumber)
{
  m_sceneQueue.push(sceneNumber);
}

bool Game::pollSceneQueue(int& returnValue)
{
  if (m_sceneQueue.empty()) return false;

  returnValue = m_sceneQueue.front();
  m_sceneQueue.pop();
  return true;
}

void Game::assignCallBack()
{
  m_scene->nextScene = [this](const int scene)
  { this->addToSceneQueue(scene); };
}


