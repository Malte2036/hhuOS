//
// Created by Malte Sehmer on 09.01.23.
//

#ifndef HHUOS_PLATFORMERBLOCKENTITY_H
#define HHUOS_PLATFORMERBLOCKENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/Sprite.h"

class PlatformerBlockEntity : public Util::Game::Entity {
public:
    explicit PlatformerBlockEntity(const Util::Memory::String &tag, const Vector2 &position,
                                   const Util::Memory::String &spriteBmpPath    );

private:
    Util::Game::Sprite *sprite;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_PLATFORMERBLOCKENTITY_H
