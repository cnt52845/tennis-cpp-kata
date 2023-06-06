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
        if (player1_points != player2_points) {
            return points_to_score(player1_points) + "-" + points_to_score(player2_points);
        }

        return points_to_score(player1_points) + "-All";
    }

private:
    static const std::string& points_to_score(int points)
    {
        static const std::array<const std::string, 4> score{"Love", "Fifteen", "Thirty", "Forty"};

        return score.at(points);
    }

    int player1_points{};
    int player2_points{};
};
