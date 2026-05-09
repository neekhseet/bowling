#ifndef GAME_H
#define GAME_H

#include <vector>

class Game {
  std::vector<int> rolls;

public:
  void roll(int pins);
  int score() const;
  int frameScore(int frame) const;
};

#endif