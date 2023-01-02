//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_MARIOITEMBLOCKENTITY_H
#define HHUOS_MARIOITEMBLOCKENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/Sprite.h"

class MarioItemBlockEntity : public Util::Game::Entity {
public:
    MarioItemBlockEntity(const Util::Memory::String &tag, const Vector2 &position);

    void onUpdate(double dt) override;

private:
    Util::Game::Sprite *sprite;

    const double size = 0.026 * 3;

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_MARIOITEMBLOCKENTITY_H
