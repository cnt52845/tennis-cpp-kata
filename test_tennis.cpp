#include <gtest/gtest.h>

#include "tennis.h"

class TennisGameTest : public ::testing::Test {
protected:
    TennisGame game;
};

TEST_F(TennisGameTest, ScoreBeforeGameBegin)
{
    EXPECT_EQ("Love-All", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredOnce)
{
    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ("Love-Fifteen", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredTwice)
{
    game.score_point(TennisGame::Player::Two);
    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ("Love-Thirty", game.get_score());
}

TEST(TennisGame, DISABLED_GetScore)
{
    auto game = TennisGame();
    EXPECT_EQ(game.get_score(), "Love-All");

    game.score_point(TennisGame::Player::One);
    EXPECT_EQ(game.get_score(), "Fifteen-Love");

    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ(game.get_score(), "Fifteen-All");

    game.score_point(TennisGame::Player::One);
    EXPECT_EQ(game.get_score(), "Thirty-Fifteen");

    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ(game.get_score(), "Thirty-All");

    game.score_point(TennisGame::Player::One);
    EXPECT_EQ(game.get_score(), "Forty-Thirty");

    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ(game.get_score(), "Deuce");

    game.score_point(TennisGame::Player::One);
    EXPECT_EQ(game.get_score(), "Advantage Player 1");

    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ(game.get_score(), "Deuce");

    game.score_point(TennisGame::Player::Two);
    EXPECT_EQ(game.get_score(), "Advantage Player 2");

    game.score_point(TennisGame::Player::One);
    game.score_point(TennisGame::Player::One);
    game.score_point(TennisGame::Player::One);
    EXPECT_EQ(game.get_score(), "Win for Player 1");
}
