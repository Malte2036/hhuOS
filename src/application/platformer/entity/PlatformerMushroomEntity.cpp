//
// Created by Malte Sehmer on 03.01.23.
//

#include "PlatformerMushroomEntity.h"
#include "lib/util/game/GameManager.h"
#include "../PlatformerGame.h"
#include "lib/util/log/Logger.h"

PlatformerMushroomEntity::PlatformerMushroomEntity(const Vector2 &position) : Util::Game::Entity("Mushroom", position) {
    sprite = new Util::Game::Sprite("/initrd/mario_mushroom.bmp", width, height);
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);
}

void PlatformerMushroomEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage(), directionLeft);
    graphics.drawRectangle(position,
                           getCollider()->getHeight(),
                           getCollider()->getWidth());
}

void PlatformerMushroomEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
}

void PlatformerMushroomEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    auto collidedWithSide = event.getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void PlatformerMushroomEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

