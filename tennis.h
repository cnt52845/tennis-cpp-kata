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
        if (is_score_tied()) {
            return get_tied_score();
        }
        return get_leading_score();
    }

private:
    bool is_score_tied() const { return player1_points == player2_points; }

    const std::string get_tied_score() const
    {
        return (player1_points < 3) ? convert_points_to_score(player1_points) + "-All" : "Deuce";
    }

    std::string get_leading_score() const
    {
        if (is_score_under_forty()) {
            return get_score_under_forty();
        }
        return get_score_above_forty();
    }

    bool is_score_under_forty() const { return (player1_points <= 3 && player2_points <= 3); }

    const std::string get_score_under_forty() const
    {
        return convert_points_to_score(player1_points) + "-" +
               convert_points_to_score(player2_points);
    }

    const std::string get_score_above_forty() const
    {
        if (is_have_winner()) {
            return "Win for Player " + get_leading_player();
        }
        return "Advantage Player " + get_leading_player();
    }

    bool is_have_winner() const { return std::abs(player1_points - player2_points) >= 2; }

    const std::string get_leading_player() const
    {
        return player1_points > player2_points ? "1" : "2";
    };

    static const std::string& convert_points_to_score(int points)
    {
        static const std::array<const std::string, 4> score{"Love", "Fifteen", "Thirty", "Forty"};
        return score.at(points);
    }

    int player1_points{};
    int player2_points{};
};
