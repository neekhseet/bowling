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

TEST(GameTest, StrikeForFirstThrowInFrame) {
  Game game;
  game.roll(10);
  game.roll(4);
  game.roll(2);
  for (int i = 0; i < 16; i++)
    game.roll(0);
  EXPECT_EQ(game.score(), 10 + 4 + 2 + 4 + 2);
}

TEST(GameTest, DoubleStrike) {
  Game game;
  game.roll(10);
  game.roll(10);
  game.roll(8);
  game.roll(1);

  for (int i = 0; i < 16; i++)
    game.roll(0);
  EXPECT_EQ(game.score(), 56);
}

TEST(GameTest, TripleStrike) {
  Game game;
  game.roll(10);
  game.roll(10);
  game.roll(10);
  game.roll(8);
  game.roll(1);

  for (int i = 0; i < 16; i++)
    game.roll(0);
  EXPECT_EQ(game.score(), 86);
}

TEST(GameTest, Spare) {
  Game game;
  game.roll(7);
  game.roll(3);
  game.roll(4);
  game.roll(2);
  for (int i = 0; i < 16; i++)
    game.roll(0);
  EXPECT_EQ(game.score(), 20);
}

TEST(GameTest, Perfect) {
  Game game;
  for (int i = 0; i < 12; i++)
    game.roll(10);
  EXPECT_EQ(game.score(), 300);
}