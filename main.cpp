#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Game.h"

TEST_CASE("Game exists","[score]")
{
    // Arrange
    auto g = new Game;
    // Assert
    REQUIRE(g != NULL);
}

TEST_CASE("Gutter Game Return 0","[score]")
{
    // Arrange
    Game g;
    int pins = 0;
    // Act
    for (int roll = 0; roll < 20; roll++) {
        g.Roll(pins);
    }
    // Assert
    REQUIRE(g.ScoreGame() == 0);
}