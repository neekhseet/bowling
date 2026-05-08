#include "../includes/game.h"

void Game::roll(int pins) { rolls.push_back(pins); };

int Game::score() const {
  int total = 0;
  int rollIndex = 0;
  for (int frame = 0; frame < 10; ++frame) {
    if (rollIndex >= rolls.size())
      break;

    if (frame == 9) {
      if (rolls[rollIndex] == 10) {
        if (rollIndex + 2 >= rolls.size())
          break;
        total += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
      } else if (rollIndex + 1 < rolls.size() &&
                 rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
        if (rollIndex + 2 >= rolls.size())
          break;
        total += 10 + rolls[rollIndex + 2];
      } else if (rollIndex + 1 < rolls.size()) {
        total += rolls[rollIndex] + rolls[rollIndex + 1];
      } else {
        break;
      }
      break;
    }

    if (rolls[rollIndex] == 10) {
      if (rollIndex + 2 >= rolls.size())
        break;
      total += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
      rollIndex += 1;
    } else if (rollIndex + 1 < rolls.size() &&
               rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
      if (rollIndex + 2 >= rolls.size())
        break;
      total += 10 + rolls[rollIndex + 2];
      rollIndex += 2;
    } else if (rollIndex + 1 < rolls.size()) {
      total += rolls[rollIndex] + rolls[rollIndex + 1];
      rollIndex += 2;
    } else {
      break;
    }
  }

  return total;
}