#pragma once

#include <cstdlib>

const int MIN_SKILL = 1;
const int MAX_SKILL = 10;

struct Enemy
{
  int skill;

  Enemy()
  {
    skill = rand() % (MAX_SKILL - MIN_SKILL) + MIN_SKILL;
  };
};
