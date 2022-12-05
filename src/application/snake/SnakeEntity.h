//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_SNAKEENTITY_H
#define HHUOS_SNAKEENTITY_H


#include "lib/util/game/Entity.h"
#include "lib/util/game/collider/RectangleCollider.h"

enum DirectionType {
    none, left, right, up, down
};

class SnakeEntity : public Util::Game::Entity {
public:
    SnakeEntity(const Vector2 &position, double size, Util::Graphic::Color color, DirectionType direction,
                double speed);

    void draw(Util::Game::Graphics2D &graphics) const override;

    void setColor(Util::Graphic::Color value);

    DirectionType getDirection();

    void setDirection(DirectionType directionType);

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const;

    void move();

private:
    Util::Graphic::Color color;
    DirectionType direction;
    double size;
    double speed;

    void onTransformEvent(Util::Game::TransformEvent *event) override;
};


#endif //HHUOS_SNAKEENTITY_H
