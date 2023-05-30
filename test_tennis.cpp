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

TEST_F(TennisGameTest, Player1ScoredOnce)
{
    game.score_player1();
    EXPECT_EQ("Fifteen-Love", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredOnce)
{
    game.score_player2();
    EXPECT_EQ("Love-Fifteen", game.get_score());
}

TEST(TennisGame, DISABLED_GetScore)
{
    auto game = TennisGame();
    EXPECT_EQ(game.get_score(), "Love-All");

    game.score_point(true);
    EXPECT_EQ(game.get_score(), "Fifteen-Love");

    game.score_point(false);
    EXPECT_EQ(game.get_score(), "Fifteen-All");

    game.score_point(true);
    EXPECT_EQ(game.get_score(), "Thirty-Fifteen");

    game.score_point(false);
    EXPECT_EQ(game.get_score(), "Thirty-All");

    game.score_point(true);
    EXPECT_EQ(game.get_score(), "Forty-Thirty");

    game.score_point(false);
    EXPECT_EQ(game.get_score(), "Deuce");

    game.score_point(true);
    EXPECT_EQ(game.get_score(), "Advantage Player 1");

    game.score_point(false);
    EXPECT_EQ(game.get_score(), "Deuce");

    game.score_point(false);
    EXPECT_EQ(game.get_score(), "Advantage Player 2");

    game.score_point(true);
    game.score_point(true);
    game.score_point(true);
    EXPECT_EQ(game.get_score(), "Win for Player 1");
}
