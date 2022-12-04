//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_DEMOSPRITE_H
#define HHUOS_DEMOSPRITE_H


#include "lib/util/game/Game.h"
#include "lib/util/game/Sprite.h"

enum DirectionType {
    left = 0,
    right = 1,
    up = 2,
    down = 3
};

class DemoSprite : public Util::Game::Sprite {
public:
    DemoSprite(double initialX, double initialY, Util::Graphic::Color initialColor, DirectionType initialDirection);

    void draw(Util::Game::Graphics2D &graphics) const override;

    DirectionType getDirection();

    void setDirection(DirectionType directionType);

private:
    DirectionType direction;
};


#endif //HHUOS_DEMOSPRITE_H
