#include "../includes/game.h"

void Game::roll(int pins) { rolls.push_back(pins); };

int Game::score() const {
  int total;

  for (int roll : rolls) {
    total += roll;
  }

  return total;
}