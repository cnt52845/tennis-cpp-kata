#include <gtest/gtest.h>

#include "tennis.h"

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
