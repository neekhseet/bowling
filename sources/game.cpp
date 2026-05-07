#include "../includes/game.h"

void Game::roll(int pins) { rolls.push_back(pins); };

int Game::score() const {
  int total = 0;
  int rollIndex = 0;
  for (int frame = 0; frame < 10; ++frame) {
    if (rolls[rollIndex] == 10) {
      total += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
      rollIndex++;
    } else {
      total += rolls[rollIndex] + rolls[rollIndex + 1];
      rollIndex += 2;
    }
  }

  return total;
}