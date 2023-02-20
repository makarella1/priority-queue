#pragma once

#include <iostream>

template <typename T>
struct DynamicArray
{
private:
  size_t size;
  size_t capacity;
  T *values;

  static constexpr size_t CAPACITY = 16;
  static constexpr float GROWTH_FACTOR = 1.5f;

public:
  DynamicArray()
  {
    size = 0;
    capacity = CAPACITY;
    values = new T[CAPACITY];
  }

  ~DynamicArray()
  {
    delete[] values;
  }

  bool isEmpty() const
  {
    return size == 0;
  }

  size_t getSize() const
  {
    return size;
  }

  void pushFront(const T &value)
  {
    reallocIfFull();

    for (size_t i = size; i > 0; i--)
    {
      values[i] = values[i - 1];
    }

    values[0] = value;

    size++;
  }

  T popFront()
  {
    if (isEmpty())
    {
      std::cerr << "Error: array is empty" << std::endl;
      exit(1);
    }

    T value = values[0];

    for (size_t i = 0; i < size; i++)
    {
      values[i] = values[i + 1];
    }

    size--;

    return value;
  }

  void pushBack(const T &value)
  {
    reallocIfFull();

    values[size++] = value;
  }

  T popBack()
  {
    if (isEmpty())
    {
      std::cerr << "Error: array is empty" << std::endl;
      exit(1);
    }

    return values[--size];
  }

  T &operator[](size_t index)
  {
    if (index > size || index < 0)
    {
      std::cerr << "Error: index out of bounds" << std::endl;
      exit(1);
    }

    return values[index];
  }

private:
  void reallocIfFull()
  {
    if (size == capacity)
    {
      capacity *= GROWTH_FACTOR;

      T *temp = new T[capacity];

      for (size_t i = 0; i < size; i++)
      {
        temp[i] = values[i];
      }

      delete[] values;

      values = temp;
    }
  }
};
