//
// Created by malte on 06.01.23.
//

#ifndef HHUOS_MARIOSCORETEXT_H
#define HHUOS_MARIOSCORETEXT_H

#include "lib/util/game/GameText.h"

class MarioScoreText : public Util::Game::GameText {

public:
    MarioScoreText(const Vector2 &position, int score);

    void increaseScore();

private:
    int score;

};


#endif //HHUOS_MARIOSCORETEXT_H
