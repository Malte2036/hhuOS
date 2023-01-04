//
// Created by malte on 03.01.23.
//

#ifndef HHUOS_MARIOMUSHROOMENTITY_H
#define HHUOS_MARIOMUSHROOMENTITY_H

#include "lib/util/game/entity/Entity.h"
#include "lib/util/game/SpriteAnimation.h"


class MarioMushroomEntity : public Util::Game::Entity {
public:
    MarioMushroomEntity(const Vector2 &position);


    void draw(Util::Game::Graphics2D &graphics) const;

    void onUpdate(double dt) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const override;

private:
    Util::Game::Sprite *sprite;

    double groundY = -0.75;

    const double speed = 0.1;

    bool directionLeft = false;

    const double height = 0.09;
    const double width = 0.08;

    Util::File::Image::Image *currentImage = nullptr;
    Util::Game::SpriteAnimation *runAnimation = nullptr;
};


#endif //HHUOS_MARIOMUSHROOMENTITY_H
