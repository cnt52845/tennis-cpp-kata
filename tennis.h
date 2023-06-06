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
        if (player1_points > player2_points) {
            if (player1_points <= 3) {
                return points_to_score(player1_points) + "-" + points_to_score(player2_points);
            }
            if (player1_points - player2_points < 2) {
                return "Advantage Player 1";
            }
            return "Win for Player 1";
        }
        if (player1_points < player2_points) {
            if (player2_points <= 3) {
                return points_to_score(player1_points) + "-" + points_to_score(player2_points);
            }
            if (player2_points - player1_points < 2) {
                return "Advantage Player 2";
            }
            return "Win for Player 2";
        }

        if (player1_points < 3) {
            return points_to_score(player1_points) + "-All";
        }
        return "Deuce";
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
