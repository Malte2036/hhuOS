//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_SNAKEENTITY_H
#define HHUOS_SNAKEENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/entity/collider/RectangleCollider.h"

enum DirectionType {
    none, left, right, up, down
};

class SnakeEntity : public Util::Game::Entity {
public:
    SnakeEntity(const Vector2 &position, double size, Util::Graphic::Color color, DirectionType direction,
                double speed);

    void onUpdate(double dt) override;

    void draw(Util::Game::Graphics2D &graphics) const override;

protected:
    void init() override;

public:

    void setColor(Util::Graphic::Color value);

    DirectionType getDirection();

    void setDirection(DirectionType directionType);

    void move();

private:
    Util::Graphic::Color color;
    DirectionType direction;
    double size;
    double speed;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;
    void onCollisionEvent(Util::Game::CollisionEvent &event) override;
};


#endif //HHUOS_SNAKEENTITY_H
