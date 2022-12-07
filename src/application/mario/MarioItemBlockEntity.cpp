//
// Created by malte on 07.12.22.
//

#include "MarioItemBlockEntity.h"

MarioItemBlockEntity::MarioItemBlockEntity(const Util::Memory::String &tag, const Vector2 &position)
        : Util::Game::Entity(tag, position) {

}

Util::Game::RectangleCollider MarioItemBlockEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, size, size);
}

void MarioItemBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(Util::Graphic::Colors::YELLOW);
    graphics.drawSquare(position, size);
}

void MarioItemBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void MarioItemBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}
