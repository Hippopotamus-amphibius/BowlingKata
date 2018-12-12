//
// Created by brettmcrae on 12/12/2018.
//

#include "Game.h"

/**
 * Adds a roll to the game score card
 * @param pinsKnockedDown
 */
void Game::Roll(int pinsKnockedDown) {
    if (spare) score += pinsKnockedDown;
    score += pinsKnockedDown;
    pinsUp -= pinsKnockedDown;
    rollNumberWithinFrame %= 1;
    spare = rollNumberWithinFrame == 2 ? pinsUp == 0 : false;
    if (pinsUp < 1) pinsUp = 0;
}

/**
 *
 * @return g
 */
int Game::ScoreGame() {
    return score;
}
