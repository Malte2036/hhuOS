//
// Created by malte on 06.12.22.
//

#ifndef HHUOS_SNAKESCORETEXT_H
#define HHUOS_SNAKESCORETEXT_H

#include "lib/util/game/GameText.h"


class SnakeScoreText : public Util::Game::GameText {
public:
    SnakeScoreText(Vector2 position, int score);

    void setScore(int value);
};


#endif //HHUOS_SNAKESCORETEXT_H
