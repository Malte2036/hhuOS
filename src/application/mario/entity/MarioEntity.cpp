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

    collider = new Util::Game::RectangleCollider(position, height * (big ? 2 : 1), width, Util::Game::DYNAMIC_COLLIDER);
}


void MarioEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    if (collider != nullptr) {
        graphics.drawRectangle(position, collider->getHeight(), collider->getWidth());
    }
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
    auto side = event->getRectangleCollidedSide();
    if (side == Util::Game::BOTTOM_SIDE) {
        canJump = true;
    }

    auto collidedWithTag = event->getCollidedWith()->getTag();
    if (collidedWithTag == "BrickBlock") {
        if (side == Util::Game::TOP_SIDE) {
            Util::Game::GameManager::getGame<MarioGame>()->removeEntity(event->getCollidedWith());
            Logger::logMessage("Mario destroyed Block");
        }
    } else if (collidedWithTag == "Mushroom") {
        Logger::logMessage("Mushroom collected");

        setBig(true);
        Util::Game::GameManager::getGame<MarioGame>()->removeEntity(event->getCollidedWith());
    } else if (event->getCollidedWith()->getTag() == "Goomba") {
        auto game = Util::Game::GameManager::getGame<MarioGame>();
        if (side == Util::Game::BOTTOM_SIDE) {
            Logger::logMessage("Player killed Goomba");
        } else {
            if (big) {
                setBig(false);
            } else {
                Logger::logMessage("Player was killed by Goomba");
                game->stop();
                return;
            }
        }
        game->removeEntity(event->getCollidedWith());
        game->spawnGoomba(position + Vector2(1, 0.25));
    }
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

void MarioEntity::setBig(bool val) {
    big = val;
    collider->setHeight(height * (big ? 2 : 1));
}
