//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_MARIOENTITY_H
#define HHUOS_MARIOENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"

class MarioEntity : public Util::Game::Entity {
public:
    MarioEntity(const Util::Memory::String &tag, const Vector2 &position);

    void onUpdate(double dt) override;

    void moveRight();
    void moveLeft();
    void jump();

private:
    const double speed = 0.75;
    const double jumpSpeed = speed * 1.25;
    const double height = 0.09;
    const double width = height;

    bool big = false;

    bool directionLeft = false;

    double groundY = -0.75;
    bool canJump = false;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;

    void setBig(bool val);
};


#endif //HHUOS_MARIOENTITY_H
