#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Game.h"

TEST_CASE("Game exists","[score]")
{
    auto g = new Game;
    // Assert
    REQUIRE(g != NULL);
}