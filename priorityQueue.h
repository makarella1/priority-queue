#pragma once

#include "dynamicArray.h"

template <typename T>
struct PriorityQueue
{
private:
  DynamicArray<T> *heap;

public:
  PriorityQueue()
  {
    heap = new DynamicArray<T>();
  }

  ~PriorityQueue()
  {
    delete heap;
  }

  void push(const T &value)
  {
    heap->pushBack(value);

    siftUp(heap->getSize() - 1);
  }

  T top()
  {
    return heap->operator[](0);
  }

  void pop()
  {
    (*heap)[0] = heap->popBack();

    siftDown(0);
  }

  bool isEmpty() const
  {
    return heap->isEmpty();
  }

  size_t size() const
  {
    return heap->getSize();
  }

private:
  int getParent(const int index)
  {
    return (index - 1) / 2;
  }

  int getLeftChild(const int index)
  {
    return 2 * index + 1;
  }

  int getRightChild(const int index)
  {
    return 2 * index + 2;
  }

  void siftUp(int index)
  {
    while (index > 0 && heap->operator[](index) > heap->operator[](getParent(index)))
    {
      std::swap(heap->operator[](index), heap->operator[](getParent(index)));

      index = getParent(index);
    }
  }

  void siftDown(const int index)
  {
    int largest = index;

    if (getLeftChild(index) < heap->getSize() && heap->operator[](getLeftChild(index)) > heap->operator[](largest))
    {
      largest = getLeftChild(index);
    }

    if (getRightChild(index) < heap->getSize() && heap->operator[](getRightChild(index)) > heap->operator[](largest))
    {
      largest = getRightChild(index);
    }

    if (largest != index)
    {
      std::swap(heap->operator[](index), heap->operator[](largest));
      siftDown(largest);
    }
  }
};