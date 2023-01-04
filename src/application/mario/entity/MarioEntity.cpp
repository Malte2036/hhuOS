//
// Created by malte on 07.12.22.
//

#include "MarioEntity.h"
#include "lib/util/log/Logger.h"
#include "lib/util/game/GameManager.h"
#include "application/mario/MarioGame.h"
#include "application/mario/block/MarioSolidBlockEntity.h"

Util::File::Image::Image *currentImage = nullptr;

Util::Game::Sprite idleSprite = Util::Game::Sprite(
        "/initrd/mario.bmp");
Util::Game::SpriteAnimation *runAnimation = nullptr;

MarioEntity::MarioEntity(const Util::Memory::String &tag, const Vector2 &position) : Util::Game::Entity(tag, position) {
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/mario_run_1.bmp"),
                    new Util::Game::Sprite(
                            "/initrd/mario_run_2.bmp"),
                    new Util::Game::Sprite(
                            "/initrd/mario_run_3.bmp")});
    currentImage = idleSprite.getImage();
}


void MarioEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    graphics.drawRectangle(position, getCollider().getHeight(), getCollider().getWidth());
}

void MarioEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    const Vector2 translateTo = event->getTranslateTo();

    auto camera = Util::Game::GameManager::getGame<MarioGame>()->getCamera();

    //calculate the left window border position offset
    auto windowBorderOffset = Util::Game::GameManager::getResolution().getX() / 2;

    if (translateTo.getX() <= (camera->getPosition().getX() - windowBorderOffset)) {
        event->setCanceled(true);
    }
    if (translateTo.getY() <= groundY) {
        event->setCanceled(true);
        canJump = true;
    }

    if (event->getTranslateTo().getX() >= camera->getPosition().getX()) {
        camera->setPosition(
                Vector2(event->getTranslateTo().getX(), 0));
    }
    if (event->isCanceled()) {
        currentImage = idleSprite.getImage();
        Logger::logMessage("setIdle");
    }
}

void MarioEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    auto collidedWithTag = event->getCollidedWith()->getTag();
    if (collidedWithTag == "BrickBlock") {
        switch (event->getRectangleCollidedSide()) {
            case Util::Game::BOTTOM_SIDE:
                canJump = true;
                break;
            case Util::Game::TOP_SIDE:
                Util::Game::GameManager::getGame<MarioGame>()->removeEntity(event->getCollidedWith());
                Logger::logMessage("Mario destroyed Block");
                break;
        }
    }
}

Util::Game::RectangleCollider MarioEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);
}

void MarioEntity::moveRight() {
    translateX(speed);
    directionLeft = false;
    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioEntity::moveLeft() {
    translateX(-speed);
    directionLeft = true;
    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioEntity::jump() {
    if (canJump) {
        translateY(jumpSpeed);
        canJump = false;
    }
}

void MarioEntity::onUpdate(double dt) {
}
