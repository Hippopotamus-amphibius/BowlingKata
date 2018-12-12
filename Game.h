//
// Created by brettmcrae on 12/12/2018.
//

#ifndef BOWLINGKATA_GAME_H
#define BOWLINGKATA_GAME_H


class Game {
    int score = 0;
public:
    void Roll(int pinsKnockedDown);
    int ScoreGame();
};


#endif //BOWLINGKATA_GAME_H
