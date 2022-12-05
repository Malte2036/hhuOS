//
// Created by malte on 05.12.22.
//

#include "FoodEntity.h"

FoodEntity::FoodEntity(const Vector2 &position, double size) : Entity(position), size{size} {}

void FoodEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(Util::Graphic::Colors::YELLOW);
    graphics.drawSquare(getPosition(), size);
}

void FoodEntity::onTransformEvent(Util::Game::TransformEvent *event) {

}

Util::Game::RectangleCollider FoodEntity::getCollider() const {
    return Util::Game::RectangleCollider(size, size);
}

