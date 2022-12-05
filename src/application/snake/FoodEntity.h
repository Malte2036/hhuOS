//
// Created by malte on 05.12.22.
//

#ifndef HHUOS_FOODENTITY_H
#define HHUOS_FOODENTITY_H


#include "lib/util/game/Entity.h"

class FoodEntity : public Util::Game::Entity {
public:
    FoodEntity(const Vector2 &position, double size);

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onTransformEvent(Util::Game::TransformEvent *event);

    [[nodiscard]] Util::Game::RectangleCollider getCollider() const;


private:
    double size;
};


#endif //HHUOS_FOODENTITY_H
