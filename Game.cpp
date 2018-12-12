//
// Created by brettmcrae on 12/12/2018.
//

#include "Game.h"

/**
 * Adds a roll to the game score card
 * @param pinsKnockedDown
 */
void Game::Roll(int pinsKnockedDown) {
    score += pinsKnockedDown;
}

/**
 *
 * @return g
 */
int Game::ScoreGame() {
    return score;
}
