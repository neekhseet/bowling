#include "../includes/game.h"
#include <gtest/gtest.h>

TEST(GameTest, GutterGame) {
  Game game;
  for (int i = 0; i < 20; i++)
    game.roll(0);
  EXPECT_EQ(game.score(), 0);
}

TEST(GameTest, AllOnes) {
  Game game;
  for (int i = 0; i < 20; i++)
    game.roll(1);
  EXPECT_EQ(game.score(), 20);
}