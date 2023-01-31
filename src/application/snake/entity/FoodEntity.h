//
// Created by Malte Sehmer on 05.12.22.
//

#ifndef HHUOS_FOODENTITY_H
#define HHUOS_FOODENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "application/snake/SnakeGame.h"

class FoodEntity : public Util::Game::Entity {
public:
    FoodEntity(const Vector2 &position, double size);

    void onUpdate(double dt) override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event) override;

    void onCollisionEvent(Util::Game::CollisionEvent *event) override;

private:
    double size;
};


#endif //HHUOS_FOODENTITY_H
