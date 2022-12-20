//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_MARIOENTITY_H
#define HHUOS_MARIOENTITY_H


#include "lib/util/game/Sprite.h"
#include "lib/util/game/entity/Entity.h"

class MarioEntity : public Util::Game::Entity {
public:
    MarioEntity(const Util::Memory::String &tag, const Vector2 &position);

    void moveRight();
    void moveLeft();
    void jump();

private:
    Util::Game::Sprite *sprite;

    const double speed = 0.75;
    const double jumpSpeed = speed * 2;
    const double size = 0.15;

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_MARIOENTITY_H
