//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_DEMOENTITY_H
#define HHUOS_DEMOENTITY_H


#include "lib/util/game/Game.h"
#include "lib/util/game/GravityEntity.h"
#include "lib/util/game/collider/RectangleCollider.h"


class DemoEntity : public Util::Game::GravityEntity {
public:
    DemoEntity(const Vector2 &position, double size, Util::Graphic::Color color);

    void draw(Util::Game::Graphics2D &graphics) const override;

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const;

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

private:
    Util::Graphic::Color color;
    double size;

    void onTransformEvent(Util::Game::TransformEvent *event) override;
    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_DEMOENTITY_H
