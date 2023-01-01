//
// Created by malte on 07.12.22.
//

#include "MarioEntity.h"
#include "lib/util/log/Logger.h"
#include "lib/util/game/GameManager.h"
#include "MarioGame.h"

bool cancelTranslate = false;

MarioEntity::MarioEntity(const Util::Memory::String &tag, const Vector2 &position) : Util::Game::Entity(tag, position),
                                                                                     sprite{new Util::Game::Sprite(
                                                                                             "/initrd/mario.bmp")} {
}

void MarioEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
}

void MarioEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if (cancelTranslate) {
        cancelTranslate = false;
        event->setCanceled(true);
        return;
    }
    auto camera = Util::Game::GameManager::getGame<MarioGame>()->getCamera();

    //calculate the left window border position offset
    auto windowBorderOffset = Util::Game::GameManager::getResolution().getX() / 2;

    const Vector2 translateTo = event->getTranslateTo();
    if (translateTo.getX() <= (camera->getPosition().getX() - windowBorderOffset)) {
        event->setCanceled(true);
    }
    if (translateTo.getY() <= -1) {
        event->setCanceled(true);
    }

    if (event->getTranslateTo().getX() >= camera->getPosition().getX()) {
        camera->setPosition(
                Vector2(event->getTranslateTo().getX(), 0));
    }
}

void MarioEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "ItemBlock") {
        Logger::logMessage("Mario collected ItemBlock");
        setPosition(Vector2(position.getX(), event->getCollidedWith()->getPosition().getY() + 0.15));
        cancelTranslate = true;
    }
}

Util::Game::RectangleCollider MarioEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, size, size);
}

void MarioEntity::moveRight() {
    translateX(speed);
}

void MarioEntity::moveLeft() {
    translateX(-speed);

}

void MarioEntity::jump() {
    if (getPosition().getY() <= (-1 + 0.025)) {
        translateY(jumpSpeed);
    }
}

void MarioEntity::onUpdate(double dt) {

}
