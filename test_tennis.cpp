#include <gtest/gtest.h>

#include "tennis.h"

class TennisGameTest : public ::testing::Test {
protected:
    TennisGame game;

    void score_player1(int times = 1)
    {
        for (int i = 0; i < times; i++) {
            game.score_point(TennisGame::Player::One);
        }
    }

    void score_player2(int times = 1)
    {
        for (int i = 0; i < times; i++) {
            game.score_point(TennisGame::Player::Two);
        }
    }
};

TEST_F(TennisGameTest, ScoreBeforeGameBegin)
{
    EXPECT_EQ("Love-All", game.get_score());
}

TEST_F(TennisGameTest, Player1ScoredOnce)
{
    score_player1();
    EXPECT_EQ("Fifteen-Love", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredOnce)
{
    score_player2();
    EXPECT_EQ("Love-Fifteen", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredTwice)
{
    score_player2(2);
    EXPECT_EQ("Love-Thirty", game.get_score());
}

TEST_F(TennisGameTest, Player2ScoredThreeTimes)
{
    score_player2(3);
    EXPECT_EQ("Love-Forty", game.get_score());
}

TEST_F(TennisGameTest, Player1ScoredOncePlayer2ScoredTwice)
{
    score_player1(1);
    score_player2(2);
    EXPECT_EQ("Fifteen-Thirty", game.get_score());
}

TEST_F(TennisGameTest, BothPlayersScoredOnce)
{
    score_player1();
    score_player2();
    EXPECT_EQ("Fifteen-All", game.get_score());
}

TEST_F(TennisGameTest, Deuce)
{
    score_player1(4);
    score_player2(4);
    EXPECT_EQ("Deuce", game.get_score());
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
