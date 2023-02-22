#include "priorityQueue.h"

template <typename T>
void heapSort(T *array, const int size)
{
  PriorityQueue<T> priorityQueue;

  for (int i = 0; i < size; i++)
  {
    priorityQueue.push(array[i]);
  }

  for (int i = size - 1; i >= 0; i--)
  {
    array[i] = priorityQueue.top();

    priorityQueue.pop();
  }
}