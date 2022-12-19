//
// Created by malte on 07.12.22.
//

#include "MarioEntity.h"
#include "lib/util/log/Logger.h"

bool cancelTranslate = false;

MarioEntity::MarioEntity(const Util::Memory::String &tag, const Vector2 &position) : GravityEntity(tag, position, 2),
                                                                                     sprite{new Util::Game::Sprite("/initrd/mario.bmp")} {

}

void MarioEntity::draw(Util::Game::Graphics2D &graphics) const {
   graphics.drawImage(position, *sprite->getImage());
}

void MarioEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if(cancelTranslate){
        cancelTranslate = false;
        event->setCanceled(true);
        return;
    }
    const Vector2 translateTo = event->getTranslateTo();
    /*if(translateTo.getX() >= 1 || translateTo.getX() <= -1){
        event->setCanceled(true);
    }*/
    if (translateTo.getY() <= -1) {
        event->setCanceled(true);
    }
}

void MarioEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "ItemBlock") {
        Logger::logMessage("Mario collected ItemBlock");
        setPosition( Vector2(position.getX(), event->getCollidedWith()->getPosition().getY() + 0.15));
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
