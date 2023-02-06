//
// Created by Malte Sehmer on 04.02.23.
//

#ifndef HHUOS_PLATFORMERPLAYERPROJECTILEENTITY_H
#define HHUOS_PLATFORMERPLAYERPROJECTILEENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/Sprite.h"

class PlatformerPlayerProjectileEntity : public Util::Game::Entity {
public:
    explicit PlatformerPlayerProjectileEntity(const Vector2 &position, const Vector2 &direction);

    ~PlatformerPlayerProjectileEntity();

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;

    void onCollisionEvent(Util::Game::CollisionEvent &event) override;

private:
    double size = 0.05;

    Vector2 direction;
    Util::Game::Sprite *sprite;
protected:
    void init() override;

private:

    Vector2 startPosition;
};


#endif //HHUOS_PLATFORMERPLAYERPROJECTILEENTITY_H
