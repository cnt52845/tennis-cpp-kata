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

    std::string get_score() const { return "Love-All"; }

private:
    int player1_points{};
    int player2_points{};
};