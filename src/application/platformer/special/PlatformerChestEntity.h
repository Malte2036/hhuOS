//
// Created by Malte Sehmer on 10.01.23.
//

#ifndef HHUOS_PLATFORMERCHESTENTITY_H
#define HHUOS_PLATFORMERCHESTENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/Sprite.h"

class PlatformerChestEntity : public Util::Game::Entity {
public:
    PlatformerChestEntity(const Vector2 &position);

private:
    Util::Game::Sprite *sprite;
    const double width = 0.05 * 2;
    const double height = 0.044 * 2;


    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;

    void onCollisionEvent(Util::Game::CollisionEvent &event) override;
};


#endif //HHUOS_PLATFORMERCHESTENTITY_H
