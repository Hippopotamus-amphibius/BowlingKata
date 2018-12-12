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
    // Act
    for (int roll = 0; roll < 20; roll++) {
        g.Roll(0);
    }
    // Assert
    REQUIRE(0 == g.ScoreGame());
}

TEST_CASE("Single Pin Game Returns 20","[score]")
{
    // Arrange
    Game g;
    // Act
    for (int roll = 0; roll < 20; roll++) {
        g.Roll(1);
    }
    // Assert
    REQUIRE(20 == g.ScoreGame());
}