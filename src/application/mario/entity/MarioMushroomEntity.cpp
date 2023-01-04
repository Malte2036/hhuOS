//
// Created by malte on 03.01.23.
//

#include "MarioMushroomEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/mario/MarioGame.h"
#include "lib/util/log/Logger.h"

MarioMushroomEntity::MarioMushroomEntity(const Vector2 &position) : Util::Game::Entity("Mushroom", position),
                                                                    sprite{new Util::Game::Sprite(
                                                                            "/initrd/mario_mushroom.bmp")} {
}

void MarioMushroomEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage(), directionLeft);
    graphics.drawRectangle(position,
                           getCollider().getHeight(),
                           getCollider().getWidth());
}

void MarioMushroomEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
}

void MarioMushroomEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        Logger::logMessage("Mushroom collected");

        Util::Game::GameManager::getGame<MarioGame>()->removeEntity(this);
        return;
    }

    if (event->getCollidedWith()->getTag() == "Mushroom") {
        return;
    }

    auto collidedWithSide = event->getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void MarioMushroomEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if (event->getTranslateTo().getY() <= groundY) {
        event->setCanceled(true);
    }
}

Util::Game::RectangleCollider MarioMushroomEntity::getCollider() const {
    return Util::Game::RectangleCollider(position,
                                         height,
                                         width,
                                         Util::Game::DYNAMIC_COLLIDER);
}

