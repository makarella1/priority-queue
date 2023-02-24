#pragma once

#include <cstdlib>

const int MIN_VALUE = 1;
const int MAX_VALUE = 100;

struct Enemy
{
  int skill;
  int damage;
  int hp;

  Enemy()
  {
    skill = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    damage = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
    hp = rand() % (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
  };
};
