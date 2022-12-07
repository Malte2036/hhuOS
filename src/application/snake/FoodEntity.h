//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_FOODENTITY_H
#define HHUOS_FOODENTITY_H


#include "lib/util/game/Entity.h"
#include "SnakeGame.h"

class FoodEntity : public Util::Game::Entity {
public:
    FoodEntity(const Vector2 &position, double size, SnakeGameData *gameData);

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTranslateEvent(Util::Game::TranslateEvent *event);

    void onCollisionEvent(Util::Game::CollisionEvent *event);

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const;


private:
    double size;
    SnakeGameData *gameData;
};


#endif //HHUOS_FOODENTITY_H
