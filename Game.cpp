//
// Created by brettmcrae on 12/12/2018.
//

#include <stdexcept>
#include "Game.h"

/**
 * Adds a roll to the game score card
 * @param pinsKnockedDown
 */
void Game::Roll(int pinsKnockedDown) {
    if (pinsKnockedDown > pinsUp)
    {
        throw std::invalid_argument("pinsKnockedDown cannot be greater than the number of pins standing");
    }
    if (subsequentRollsToDouble > 0)
    {
        score += pinsKnockedDown;
        subsequentRollsToDouble--;
    }
    score += pinsKnockedDown;
    pinsUp -= pinsKnockedDown;
    if (pinsUp == 0)
    {
        subsequentRollsToDouble += pinsKnockedDown == 10 ? 2 : 1;
    }
    if (rollNumberWithinFrame == 2 || pinsUp == 0)
    {
        pinsUp = 10;
        rollNumberWithinFrame = 1;
    } else{
        rollNumberWithinFrame++;
    }
}

/**
 *
 * @return g
 */
int Game::ScoreGame() {
    return score;
}
