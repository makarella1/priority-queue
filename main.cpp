#include <iostream>
#include <ctime>

#include "dynamicArray.h"
#include "enemy.h"
#include "priorityQueue.h"

// bool operator==(const Enemy &firstEnemy, const Enemy &secondEnemy);

// bool operator<(const Enemy &firstEnemy, const Enemy &secondEnemy);

int main()
{
  srand(time(NULL));

  DynamicArray<Enemy> array;
  PriorityQueue<int> priorityQueue;

  priorityQueue.push(3);
  priorityQueue.push(1);
  priorityQueue.push(4);
  priorityQueue.push(1);
  priorityQueue.push(5);

  while (!priorityQueue.isEmpty())
  {
    std::cout << "size: " << priorityQueue.size() << std::endl;

    std::cout << priorityQueue.top() << std::endl;

    priorityQueue.pop();

    std::cout << "popped" << std::endl;
  }

  priorityQueue.pop();

  std::cout << priorityQueue.size() << std::endl;
}

// bool operator==(const Enemy &firstEnemy, const Enemy &secondEnemy)
// {
//   return firstEnemy.skill == secondEnemy.skill;
// }

// bool operator<(const Enemy &firstEnemy, const Enemy &secondEnemy)
// {
//   return firstEnemy.skill < secondEnemy.skill;
// }

// bool operator>(const Enemy &firstEnemy, const Enemy &secondEnemy)
// {
//   return firstEnemy.skill > secondEnemy.skill;
// }
