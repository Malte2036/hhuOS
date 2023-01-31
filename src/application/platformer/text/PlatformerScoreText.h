//
// Created by Malte Sehmer on 06.01.23.
//

#ifndef HHUOS_PLATFORMERSCORETEXT_H
#define HHUOS_PLATFORMERSCORETEXT_H

#include "lib/util/game/GameText.h"

class PlatformerScoreText : public Util::Game::GameText {

public:
    PlatformerScoreText(const Vector2 &position, int score);

    void increaseScore();

private:
    int score;

};


#endif //HHUOS_PLATFORMERSCORETEXT_H
