#include <iostream>
#include <ctime>
#include <queue>
#include <algorithm>

#include "dynamicArray.h"
#include "enemy.h"
#include "heapSort.h"
#include "game.h"
#include "priorityQueue.h"

const long ARRAY_SIZE = 1000000;

bool operator==(const Enemy &firstEnemy, const Enemy &secondEnemy);
bool operator<(const Enemy &firstEnemy, const Enemy &secondEnemy);
bool operator>(const Enemy &firstEnemy, const Enemy &secondEnemy);

template <typename T>
float testPriorityQueueSpeed(T &&priorityQueue);
bool testPriorityQueue();
void testSort();

int main()
{
  srand(time(NULL));

  testSort();
  // Game().start();

  // testPriorityQueue();
}

bool testPriorityQueue()
{
  srand(time(NULL));
  const int iters = 1000000;
  PriorityQueue<Enemy> myPriorQueue;
  std::priority_queue<Enemy> stlPriorQueue;
  bool isDataEqual = true;
  for (int i = 0; i < iters; i++)
  {
    int insertDataAmount = rand() % 6 + 5;
    for (int j = 0; j < insertDataAmount; j++)
    {
      Enemy randData = Enemy();
      myPriorQueue.push(randData);
      stlPriorQueue.push(randData);
    }
    if (!(myPriorQueue.top() == stlPriorQueue.top()))
    {
      isDataEqual = false;
      std::cerr << "Comparing failed on iteration " << i << std::endl
                << std::endl;
      break;
    }
    int removeDataAmount = rand() % insertDataAmount;
    for (int j = 0; j < removeDataAmount; j++)
    {
      myPriorQueue.pop();
      stlPriorQueue.pop();
    }
  }
  int myQueueSize = myPriorQueue.size();
  int stlQueueSize = stlPriorQueue.size();
  float stlTime = testPriorityQueueSpeed(myPriorQueue);
  float myTime = testPriorityQueueSpeed(stlPriorQueue);
  std::cout << "My PriorityQueue:" << std::endl;
  std::cout << "Time: " << myTime << ", size: " << myQueueSize << std::endl;
  std::cout << "STL priority_queue:" << std::endl;
  std::cout << "Time: " << stlTime << ", size: " << stlQueueSize << std::endl
            << std::endl;
  if (isDataEqual && myQueueSize == stlQueueSize)
  {
    std::cout << "The lab is completed" << std::endl
              << std::endl;
    return true;
  }
  std::cerr << ":(" << std::endl
            << std::endl;

  return false;
}

template <typename T>
float testPriorityQueueSpeed(T &&priorityQueue)
{
  const int iters = 1000000;
  clock_t timeStart = clock();
  for (int i = 0; i < iters; i++)
  {
    int insertDataAmount = rand() % 6 + 5;
    for (int j = 0; j < insertDataAmount; j++)
    {
      priorityQueue.push(Enemy());
    }
    priorityQueue.top();
    priorityQueue.pop();
  }
  clock_t timeEnd = clock();
  float time = (float(timeEnd - timeStart)) / CLOCKS_PER_SEC;
  return time;
}

void testSort()
{
  int *toSort = new int[ARRAY_SIZE];

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    toSort[i] = rand() % ARRAY_SIZE;
  }

  clock_t myStart = clock();
  heapSort(toSort, ARRAY_SIZE);
  clock_t myEnd = clock();

  float myTime = (float(myEnd - myStart)) / CLOCKS_PER_SEC;

  std::cout << "MY TIME: " << myTime << std::endl;

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    toSort[i] = rand() % ARRAY_SIZE;
  }

  clock_t stlStart = clock();
  std::sort(toSort, toSort + ARRAY_SIZE);
  clock_t stlEnd = clock();

  float stlTime = (float(stlEnd - stlStart)) / CLOCKS_PER_SEC;

  std::cout << "STL's TIME: " << stlTime << std::endl;
}

bool operator==(const Enemy &firstEnemy, const Enemy &secondEnemy)
{
  return firstEnemy.skill == secondEnemy.skill;
}

bool operator<(const Enemy &firstEnemy, const Enemy &secondEnemy)
{
  return firstEnemy.skill < secondEnemy.skill;
}

bool operator>(const Enemy &firstEnemy, const Enemy &secondEnemy)
{
  return firstEnemy.skill > secondEnemy.skill;
}
