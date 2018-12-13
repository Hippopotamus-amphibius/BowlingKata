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

TEST_CASE("Gutter Game Scores 0","[score]")
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

TEST_CASE("Single Pin Game Scores 20","[score]")
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

TEST_CASE("Roll 5, 5 (spare), 3 Scores 16","[score]")
{
    // Arrange
    Game g;
    // Act
    g.Roll(5);
    g.Roll(5);
    g.Roll(3);
    for (int roll = 0; roll < 17; roll++) {
        g.Roll(0);
    }
    // Assert
    REQUIRE(16 == g.ScoreGame());
}

TEST_CASE("Knocking Down more pins than are up is an exception", "[score]")
{
    // Arrange
    Game g;
    // Act
    // Assert
    REQUIRE_THROWS_AS(g.Roll(11), std::invalid_argument);
}

TEST_CASE("Knocking Down more pins than are up is an exception (2)", "[score]")
{
    // Arrange
    Game g;
    // Act
    g.Roll(5);
    // Assert
    REQUIRE_THROWS_AS(g.Roll(6), std::invalid_argument);
}

TEST_CASE("Roll 10 (strike), 3, 4 Scores 24","[score]")
{
    // Arrange
    Game g;
    // Act
    g.Roll(10);
    g.Roll(3);
    g.Roll(4);
    for (int roll = 0; roll < 16; roll++) {
        g.Roll(0);
    }
    // Assert
    REQUIRE(24 == g.ScoreGame());
}