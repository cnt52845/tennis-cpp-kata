#pragma once

#include <string>

class TennisGame {
public:
    TennisGame() = default;

    void score_point(bool is_player1_scored)
    {
        if (is_player1_scored)
            player1_points += 1;
        else
            player2_points += 1;
    }

    void score_player1() { is_player1_scored = true; }

    void score_player2() { is_player2_scored = true; }

    std::string get_score() const
    {
        if (is_player1_scored) {
            return "Fifteen-Love";
        }
        if (is_player2_scored) {
            return "Love-Fifteen";
        }
        return "Love-All";
    }

private:
    bool is_player1_scored{false};
    bool is_player2_scored{false};
    int  player1_points{};
    int  player2_points{};
};