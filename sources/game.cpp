#include "../includes/game.h"

void Game::roll(int pins) { rolls.push_back(pins); };

int Game::score() const {
  int total = 0;
  int rollIndex = 0;
  for (int frame = 0; frame < MAX_FRAMES; ++frame) {
    if (rollIndex >= rolls.size())
      break;

    if (frame == MAX_FRAMES - 1) {
      if (rolls[rollIndex] == MAX_PINS) {
        if (rollIndex + 2 >= rolls.size())
          break;
        total += MAX_PINS + rolls[rollIndex + 1] + rolls[rollIndex + 2];
      } else if (rollIndex + 1 < rolls.size() &&
                 rolls[rollIndex] + rolls[rollIndex + 1] == MAX_PINS) {
        if (rollIndex + 2 >= rolls.size())
          break;
        total += MAX_PINS + rolls[rollIndex + 2];
      } else if (rollIndex + 1 < rolls.size()) {
        total += rolls[rollIndex] + rolls[rollIndex + 1];
      } else {
        break;
      }
      break;
    }

    if (rolls[rollIndex] == MAX_PINS) {
      if (rollIndex + 2 >= rolls.size())
        break;
      total += MAX_PINS + rolls[rollIndex + 1] + rolls[rollIndex + 2];
      rollIndex += 1;
    } else if (rollIndex + 1 < rolls.size() &&
               rolls[rollIndex] + rolls[rollIndex + 1] == MAX_PINS) {
      if (rollIndex + 2 >= rolls.size())
        break;
      total += MAX_PINS + rolls[rollIndex + 2];
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

int Game::frameScore(int frame) const {
  int rollIndex = startFrameIndex(frame);

  if (rollIndex >= rolls.size())
    return 0;

  if (rolls[rollIndex] == MAX_PINS) {
    if (rollIndex + 2 >= rolls.size())
      return 0;
    return MAX_PINS + rolls[rollIndex + 1] + rolls[rollIndex + 2];
  }

  if (rollIndex + 1 >= rolls.size())
    return 0;

  if (rolls[rollIndex] + rolls[rollIndex + 1] == MAX_PINS) {
    if (rollIndex + 2 >= rolls.size())
      return 0;
    return MAX_PINS + rolls[rollIndex + 2];
  }

  return rolls[rollIndex] + rolls[rollIndex + 1];
}

int Game::rollScore(int frame, int roll) const {
  int rollIndex = startFrameIndex(frame);

  if (rollIndex >= rolls.size())
    return 0;

  if (roll == 2 && rolls[rollIndex] == MAX_PINS)
    return 0;

  if (rollIndex + (roll - 1) >= rolls.size())
    return 0;

  return rolls[rollIndex + (roll - 1)];
}

int Game::startFrameIndex(int frame) const {
  int rollIndex = 0;

  for (int f = 1; f < frame; ++f) {
    if (rollIndex >= rolls.size())
      return 0;
    if (rolls[rollIndex] == MAX_PINS)
      rollIndex += 1;
    else
      rollIndex += 2;
  }

  return rollIndex;
}

int Game::scoreFrameInternal(int rollIndex) const {

  if (rolls[rollIndex] == MAX_PINS)
    return MAX_PINS + rolls[rollIndex + 1] + rolls[rollIndex + 2];
  else if (rolls[rollIndex] + rolls[rollIndex + 1] == MAX_PINS)
    return MAX_PINS + rolls[rollIndex + 2];

  return rolls[rollIndex] + rolls[rollIndex + 1];
}