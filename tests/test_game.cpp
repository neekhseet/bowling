#include "../includes/game.h"
#include <gtest/gtest.h>
#include <stdexcept>

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

TEST(GameTest, TenthFrameStrike) {
  Game game;
  for (int i = 0; i < 18; i++)
    game.roll(0);
  game.roll(10);
  game.roll(4);
  game.roll(3);
  EXPECT_EQ(game.score(), 17);
}

TEST(GameTest, TenthFrameSpare) {
  Game game;
  for (int i = 0; i < 18; i++)
    game.roll(0);
  game.roll(6);
  game.roll(4);
  game.roll(3);
  EXPECT_EQ(game.score(), 13);
}

TEST(GameTest, NoScoreForIncompleteFrame) {
  Game game;
  game.roll(3);
  EXPECT_EQ(game.score(), 0);
  game.roll(5);
  EXPECT_EQ(game.score(), 8);
  game.roll(3);
  EXPECT_EQ(game.score(), 8);
  game.roll(3);
  EXPECT_EQ(game.score(), 14);
}

TEST(GameTest, ScoreWithStrike) {
  Game game;
  game.roll(10);
  EXPECT_EQ(game.score(), 0);
  game.roll(3);
  EXPECT_EQ(game.score(), 0);
  game.roll(4);
  EXPECT_EQ(game.score(), 24);
}

TEST(GameTest, SecondFrameScore) {
  Game game;
  game.roll(0);
  game.roll(2);
  game.roll(3);
  game.roll(5);
  for (int i = 0; i < 16; ++i)
    game.roll(0);
  EXPECT_EQ(game.frameScore(2), 8);
}

TEST(GameTest, FrameScoreWithStrike) {
  Game game;
  game.roll(10);
  game.roll(5);
  game.roll(4);

  for (int i = 0; i < 17; ++i)
    game.roll(0);
  EXPECT_EQ(game.frameScore(1), 19);
}

TEST(GameTest, FrameScoreWithSpare) {
  Game game;
  game.roll(6);
  game.roll(4);
  game.roll(5);
  for (int i = 0; i < 17; ++i)
    game.roll(0);
  EXPECT_EQ(game.frameScore(1), 15);
}

TEST(GameTest, FrameScoreOfTenthFrameWithStrike) {
  Game game;
  for (int i = 0; i < 18; ++i)
    game.roll(0);
  game.roll(10);
  game.roll(4);
  game.roll(3);
  EXPECT_EQ(game.frameScore(10), 17);
}

TEST(GameTest, FrameScoreOfTenthFrameWithSpare) {
  Game game;
  for (int i = 0; i < 18; ++i)
    game.roll(0);
  game.roll(6);
  game.roll(4);
  game.roll(3);
  EXPECT_EQ(game.frameScore(10), 13);
}

TEST(GameTest, FrameScoreOfTenthFrame) {
  Game game;
  for (int i = 0; i < 18; ++i)
    game.roll(0);
  game.roll(4);
  game.roll(4);
  EXPECT_EQ(game.frameScore(10), 8);
}

TEST(GameTest, FrameScoreAfterStrike) {
  Game game;
  game.roll(10);
  game.roll(2);
  game.roll(3);
  EXPECT_EQ(game.frameScore(2), 5);
}

TEST(GameTest, FrameScoreTenthFrameIncomplete) {
  Game game;
  for (int i = 0; i < 18; ++i)
    game.roll(0);
  game.roll(10);
  EXPECT_EQ(game.frameScore(10), 0);
}

TEST(GameTest, SecondRollInFirstFrame) {
  Game game;
  game.roll(0);
  game.roll(5);
  for (int i = 0; i < 18; ++i)
    game.roll(0);
  EXPECT_EQ(game.rollScore(1, 2), 5);
}

TEST(GameTest, RollScoreWithStrike) {
  Game game;
  game.roll(0);
  game.roll(5);
  game.roll(10);
  game.roll(5);
  game.roll(4);
  EXPECT_EQ(game.rollScore(1, 1), 0);
  EXPECT_EQ(game.rollScore(1, 2), 5);
  EXPECT_EQ(game.rollScore(2, 1), 10);
  EXPECT_EQ(game.rollScore(2, 2), 0);
  EXPECT_EQ(game.rollScore(3, 1), 5);
  EXPECT_EQ(game.rollScore(3, 2), 4);
}

TEST(GameTest, RollOutOfRange) {
  Game game;
  EXPECT_THROW(game.roll(11), std::out_of_range);
  EXPECT_THROW(game.roll(0), std::out_of_range);
}