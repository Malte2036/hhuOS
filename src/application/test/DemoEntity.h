//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_DEMOENTITY_H
#define HHUOS_DEMOENTITY_H


#include "lib/util/game/Game.h"
#include "lib/util/game/Entity.h"

enum DirectionType {
    left = 0,
    right = 1,
    up = 2,
    down = 3
};

class DemoEntity : public Util::Game::Entity {
public:
    DemoEntity(Vector2 position, double size, Util::Graphic::Color color, DirectionType direction);

    void draw(Util::Game::Graphics2D &graphics) const override;

    DirectionType getDirection();

    void setDirection(DirectionType directionType);

private:
    DirectionType direction;
};


#endif //HHUOS_DEMOENTITY_H
