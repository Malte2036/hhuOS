//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_FOODENTITY_H
#define HHUOS_FOODENTITY_H


#include "lib/util/game/entity/Entity.h"
#include "SnakeGame.h"

class FoodEntity : public Util::Game::Entity {
public:
    FoodEntity(const Vector2 &position, double size, SnakeGameData *gameData);

    void onUpdate(double dt) override;

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event);

    void onCollisionEvent(Util::Game::CollisionEvent *event);

private:
    double size;
    SnakeGameData *gameData;
};


#endif //HHUOS_FOODENTITY_H
