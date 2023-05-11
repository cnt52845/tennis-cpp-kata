# Tennis C++ Kata

[![CI](https://github.com/Coding-Cuddles/tennis-cpp-kata/actions/workflows/main.yml/badge.svg)](https://github.com/Coding-Cuddles/tennis-cpp-kata/actions/workflows/main.yml)
[![Replit](https://replit.com/badge?caption=Try%20with%20Replit&variant=small)](https://replit.com/new/github/Coding-Cuddles/tennis-cpp-kata)

## Overview

This kata complements [Clean Code: Fundamentals, Ep. 4 - Function Structure](https://cleancoders.com/episode/clean-code-episode-4).

The rules of the tennis kata are as follows:

* The game is played by two players, called "Player 1" and "Player 2".
* The players start with a score of 0 points each.
* The players take turns hitting the ball over the net, with Player 1 serving
  first.
* The game continues until one of the players reaches a score of 4 points.
* If a player reaches a score of 4 points, they must have a lead of at least 2
  points over the other player in order to win the game. For example, if player
  1 has a score of 4 and player 2 has a score of 3, the game continues.
* If the scores are tied at 4 points each, the game enters the "Deuce" mode. In
  deuce mode, the players continue to play until one of them has a lead of 2
  points.

For more information on the rules of tennis, please see
the [official rules](https://www.itftennis.com/en/about-us/governance/rules-and-regulations/)
from International Tennis Federation.

## Instructions

To complete the kata, your code should include the following features:

* A function that keeps track of the score for each player: this function
  should be able to increment the score for a player when they win a point.
* A function that returns a string representation of the current score.

The rules for scoring representation are as follows:

* If both players have the same number of points, the score is described as
  "Love-All", "Fifteen-All", "Thirty-All", or "Deuce" depending on the number
  of points scored.
* If one player has scored four or more points and has a two-point lead over
  the other player, the score is described as "Win for Player 1" or "Win for
  Player 2" depending on which player has won.
* If one player has scored four or more points and has a one-point lead over
  the other player, the score is described as "Advantage Player 1" or
  "Advantage Player 2" depending on which player has the advantage.
* If both players have scored less than four points, the score is described as
  "Love", "Fifteen", "Thirty", or "Forty" depending on the number of points
  scored by each player.

## Usage

You can import this project into [Replit](https://replit.com), and it will
handle all dependencies automatically.

### Prerequisites

* [CMake 3.19+](https://cmake.org)
* [Ninja](https://ninja-build.org)
* [GTest](https://github.com/google/googletest)

### Build

```console
make
```

### Run main

```console
make run
```

### Run tests

```console
make test
```
