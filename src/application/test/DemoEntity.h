//
// Created by malte on 04.12.22.
//

#ifndef HHUOS_DEMOENTITY_H
#define HHUOS_DEMOENTITY_H


#include "lib/util/game/Game.h"
#include "lib/util/game/Sprite.h"
#include "lib/util/game/collider/RectangleCollider.h"


class DemoEntity : public Util::Game::Entity {
public:
    DemoEntity(const Vector2 &position, double size);

    void draw(Util::Game::Graphics2D &graphics) const override;

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const;

    void moveRight();

    void moveLeft();

    void jump();

private:
    Util::Graphic::Color color;
    double size;

    Util::Game::Sprite sprite;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_DEMOENTITY_H
