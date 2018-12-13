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
    ValidateRoll(pinsKnockedDown);
    AddSpareStrikeBonusToScore(pinsKnockedDown);
    score += pinsKnockedDown;
    pinsUp -= pinsKnockedDown;
    SetUpSpareStrikeBonus(pinsKnockedDown);
    SetUpNextRoll();
}

void Game::ValidateRoll(int pinsKnockedDown)
{
    if (pinsKnockedDown > pinsUp)
    {
        throw std::invalid_argument("pinsKnockedDown cannot be greater than the number of pins standing");
    }
}

void Game::AddSpareStrikeBonusToScore(int pinsKnockedDown) {
    if (subsequentRollsToDouble > 0)
    {
        score += pinsKnockedDown;
        subsequentRollsToDouble--;
    }
}

void Game::SetUpSpareStrikeBonus(int pinsKnockedDown) {
    if (pinsUp == 0)
    {
        if (pinsKnockedDown == 10) subsequentRollsToDouble += 2;
        else subsequentRollsToDouble++;
    }
}

void Game::SetUpNextRoll() {
    if (rollNumberWithinFrame == 2 || pinsUp == 0)
    {
        pinsUp = 10;
        rollNumberWithinFrame = 1;
    }
    else
    {
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
