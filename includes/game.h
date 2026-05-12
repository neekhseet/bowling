#ifndef GAME_H
#define GAME_H

#include <stdexcept>
#include <vector>

class Game {
  static constexpr int MAX_FRAMES = 10;
  static constexpr int MAX_PINS = 10;
  std::vector<int> rolls;

  int startFrameIndex(int frame) const;
  int scoreFrameInternal(int rollIndex) const;

public:
  void roll(int pins);
  int score() const;
  int frameScore(int frame) const;
  int rollScore(int frame, int roll) const;
};

#endif