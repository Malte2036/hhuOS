//
// Created by Malte Sehmer on 03.01.23.
//

#ifndef HHUOS_PLATFORMERNINJAENTITY_H
#define HHUOS_PLATFORMERNINJAENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"


class PlatformerNinjaEntity : public Util::Game::Entity {
public:
    explicit PlatformerNinjaEntity(const Vector2 &position);

    /**
    * Destructor.
    */
    ~PlatformerNinjaEntity() override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    void onCollisionEvent(Util::Game::CollisionEvent &event) override;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;

private:
    const double speed = 0.3;

    const double height = 0.1;
    const double width = 0.07;

    bool directionLeft = true;

    Util::File::Image::Image *currentImage = nullptr;
    Util::Game::SpriteAnimation *runAnimation = nullptr;
};


#endif //HHUOS_PLATFORMERNINJAENTITY_H
