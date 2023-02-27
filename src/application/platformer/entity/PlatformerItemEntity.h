//
// Created by Malte Sehmer on 03.01.23.
//

#ifndef HHUOS_PLATFORMERITEMENTITY_H
#define HHUOS_PLATFORMERITEMENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"


class PlatformerItemEntity : public Util::Game::Entity {
public:
    explicit PlatformerItemEntity(const Vector2 &position);

    /**
    * Destructor.
    */
    ~PlatformerItemEntity() override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

protected:
    void init() override;

public:

    void onCollisionEvent(Util::Game::CollisionEvent &event) override;

    void onTranslateEvent(Util::Game::TranslateEvent &event) override;

private:
    Util::Game::Sprite *sprite;

    const double speed = 0.1;

    bool directionLeft = false;

    const double height = 0.07;
    const double width = 0.08;

    Util::File::Image::Image *currentImage = nullptr;
    Util::Game::SpriteAnimation *runAnimation = nullptr;
};


#endif //HHUOS_PLATFORMERITEMENTITY_H
