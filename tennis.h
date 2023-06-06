#pragma once

#include <string>

class TennisGame {
public:
    TennisGame() = default;

    enum class Player { One, Two };

    void score_point(Player player)
    {
        switch (player) {
        case Player::One:
            player1_points++;
            break;

        case Player::Two:
            player2_points++;
            break;
        }
    }

    std::string get_score() const
    {
        switch (player2_points) {
        case 1:
            return "Love-Fifteen";

        case 2:
            return "Love-Thirty";

        case 3:
            return "Love-Forty";
        }

        return "Love-All";
    }

private:
    int player1_points{};
    int player2_points{};
};