//
// Created by Malte Sehmer on 03.01.23.
//

#ifndef HHUOS_PLATFORMERMUSHROOMENTITY_H
#define HHUOS_PLATFORMERMUSHROOMENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"


class PlatformerMushroomEntity : public Util::Game::Entity {
public:
    explicit PlatformerMushroomEntity(const Vector2 &position);


    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    void onCollisionEvent(Util::Game::CollisionEvent &event) override;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;

private:
    Util::Game::Sprite *sprite;

    const double speed = 0.1;

    bool directionLeft = false;

    const double height = 0.09;
    const double width = 0.08;

    Util::File::Image::Image *currentImage = nullptr;
    Util::Game::SpriteAnimation *runAnimation = nullptr;
};


#endif //HHUOS_PLATFORMERMUSHROOMENTITY_H
