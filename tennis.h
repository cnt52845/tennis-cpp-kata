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
        if (isPlayer1Leads()) {
            return score_player1_leads();
        }

        if (isPlayer2Leads()) {
            return score_player2_leads();
        }

        return tied_score();
    }

private:
    bool isPlayer1Leads() const { return player1_points > player2_points; }

    bool isPlayer2Leads() const { return player1_points < player2_points; }

    const std::string score_player1_leads() const
    {
        if (player1_points <= 3) {
            return score_until_deuce();
        }
        if (player1_points - player2_points < 2) {
            return "Advantage Player 1";
        }
        return "Win for Player 1";
    }

    const std::string score_player2_leads() const
    {
        if (player2_points <= 3) {
            return score_until_deuce();
        }
        if (player2_points - player1_points < 2) {
            return "Advantage Player 2";
        }
        return "Win for Player 2";
    }

    const std::string score_until_deuce() const
    {
        return points_to_score(player1_points) + "-" + points_to_score(player2_points);
    }

    const std::string tied_score() const
    {
        if (player1_points < 3) {
            return points_to_score(player1_points) + "-All";
        }
        return "Deuce";
    }

    static const std::string& points_to_score(int points)
    {
        static const std::array<const std::string, 4> score{"Love", "Fifteen", "Thirty", "Forty"};

        return score.at(points);
    }

    int player1_points{};
    int player2_points{};
};
