//
// Created by brettmcrae on 12/12/2018.
//

#include "Game.h"

/**
 * Adds a roll to the game score card
 * @param pinsKnockedDown
 */
void Game::Roll(int pinsKnockedDown) {
    if (subsequentRollsToDouble > 0)
    {
        score += pinsKnockedDown;
        subsequentRollsToDouble--;
    }
    score += pinsKnockedDown;
    pinsUp -= pinsKnockedDown;
    if (pinsUp == 0)
    {
        subsequentRollsToDouble++;
    }
    if (rollNumberWithinFrame == 2) pinsUp = 10;
    rollNumberWithinFrame = rollNumberWithinFrame == 1 ? 2 : 1;
}

/**
 *
 * @return g
 */
int Game::ScoreGame() {
    return score;
}
