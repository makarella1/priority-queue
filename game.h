#pragma once

#include "priorityQueue.h"
#include "enemy.h"
#include <iostream>

enum class Turns
{
  CHOOSING,
  PRINT_ENEMIES,
  ADD_ENEMIES,
  DESTROY_ENEMIES,
  EXIT
};

struct Game
{
private:
  PriorityQueue<Enemy> priorityQueue;

  Turns turn;

  int choose()
  {
    int option;

    std::cout << "What's your choice?" << std::endl;

    std::cout << "1. Print All the Enemies" << std::endl;
    std::cout << "2. Add Enemies" << std::endl;
    std::cout << "3. Destroy Enemies" << std::endl;
    std::cout << "4. Exit" << std::endl;

    std::cin >> option;

    return option;
  }

public:
  Game()
  {
    turn = Turns::CHOOSING;
  }

  void start()
  {
    while (turn != Turns::EXIT)
    {
      switch (turn)
      {
      case Turns::CHOOSING:
        turn = static_cast<Turns>(choose());

        std::cout << "\n";

        break;
      case Turns::ADD_ENEMIES:
        int enemies;

        std::cout << "How many enemies do you want to add?" << std::endl;

        std::cin >> enemies;

        for (int i = 0; i < enemies; i++)
        {
          priorityQueue.push(Enemy());
        }

        std::cout << "Added " << enemies << " enemies!" << std::endl;

        turn = Turns::CHOOSING;

        std::cout << "\n";

        break;
      case Turns::PRINT_ENEMIES:
        for (int i = 0; i < priorityQueue.size(); i++)
        {
          std::cout << "#" << i << " enemy's skill is: " << priorityQueue.get(i).skill << std::endl;
        }

        std::cout << "\n";

        turn = Turns::CHOOSING;

        break;
      case Turns::DESTROY_ENEMIES:
        int destroyCount;

        std::cout << "How many enemies do you want to destroy?" << std::endl;

        std::cin >> destroyCount;

        for (int i = 0; i < destroyCount; i++)
        {
          priorityQueue.pop();
        }

        std::cout << "\n";

        turn = Turns::CHOOSING;

        break;
      default:
        turn = Turns::CHOOSING;

        break;
      }
    }
  }
};