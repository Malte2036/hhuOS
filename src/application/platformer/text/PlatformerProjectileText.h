//
// Created by Malte Sehmer on 06.01.23.
//

#ifndef HHUOS_PLATFORMERPROJECTILETEXT_H
#define HHUOS_PLATFORMERPROJECTILETEXT_H

#include "lib/util/game/GameText.h"

class PlatformerProjectileText : public Util::Game::GameText {

public:
    explicit PlatformerProjectileText(const Vector2 &position);

    void setCount(int value);

};


#endif //HHUOS_PLATFORMERPROJECTILETEXT_H
