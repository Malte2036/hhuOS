//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERPLAYERENTITY_H
#define HHUOS_PLATFORMERPLAYERENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"

class PlatformerPlayerEntity : public Util::Game::Entity {
public:
    PlatformerPlayerEntity(const Util::Memory::String &tag, const Vector2 &position, double groundY);

    void onUpdate(double dt) override;

    void moveRight();
    void moveLeft();
    void jump();

private:
    const double speed = 0.75;
    const double jumpSpeed = speed * 1.35;
    const double height = 0.1;
    const double width = height;

    bool big = false;

    bool directionLeft = false;

    const double groundY;
    bool canJump = false;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;

    void setBig(bool val);
};


#endif //HHUOS_PLATFORMERPLAYERENTITY_H
