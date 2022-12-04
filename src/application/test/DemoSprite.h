//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_DEMOSPRITE_H
#define HHUOS_DEMOSPRITE_H


#include "lib/util/game/Game.h"
#include "lib/util/game/Sprite.h"

class DemoSprite : public Util::Game::Sprite {
public:
    DemoSprite(double initialX, double initialY, Util::Graphic::Color initialColor);

    void draw(Util::Game::Graphics2D &graphics) const override;
};


#endif //HHUOS_DEMOSPRITE_H
