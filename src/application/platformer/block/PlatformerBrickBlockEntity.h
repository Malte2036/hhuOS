//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERBRICKBLOCKENTITY_H
#define HHUOS_PLATFORMERBRICKBLOCKENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/Sprite.h"

class PlatformerBrickBlockEntity : public Util::Game::Entity {
public:
    explicit PlatformerBrickBlockEntity(const Vector2 &position);

    void onUpdate(double dt) override;

private:
    Util::Game::Sprite *sprite;

    const double size = 0.075;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_PLATFORMERBRICKBLOCKENTITY_H
