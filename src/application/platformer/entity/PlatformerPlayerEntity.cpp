//
// Created by Malte Sehmer on 07.12.22.
//

#include "PlatformerPlayerEntity.h"
#include "lib/util/log/Logger.h"
#include "lib/util/game/GameManager.h"
#include "../PlatformerGame.h"

Util::File::Image::Image *currentImage = nullptr;

Util::Game::Sprite *idleSprite = nullptr;
Util::Game::SpriteAnimation *runAnimation = nullptr;

PlatformerPlayerEntity::PlatformerPlayerEntity(const Util::Memory::String &tag, const Vector2 &position,
                                               const double groundY)
        : Util::Game::Entity(tag, position), groundY{groundY} {
    idleSprite = new Util::Game::Sprite("/initrd/game/platformer/player/run/player_run_1.bmp", width, height);
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_1.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_2.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_3.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_4.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_5.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_6.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_7.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_8.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/player/run/player_run_9.bmp", width, height)});
    currentImage = idleSprite->getImage();

    collider = new Util::Game::RectangleCollider(position, height * (big ? 2 : 1), width, Util::Game::DYNAMIC_COLLIDER);
}


void PlatformerPlayerEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    if (collider != nullptr) {
        //graphics.drawRectangle(position, collider->getHeight(), collider->getWidth());
    }
}

void PlatformerPlayerEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    const Vector2 translateTo = event->getTranslateTo();

    auto camera = Util::Game::GameManager::getGame<PlatformerGame>()->getScene()->getCamera();

    //calculate the left window border position offset
    auto windowBorderOffset = Util::Game::GameManager::getResolution().getX() / 2;

    if (translateTo.getX() <= (camera->getPosition().getX() - windowBorderOffset)) {
        event->setCanceled(true);
    }
    if (translateTo.getY() < groundY - 0.2) {
        Util::Game::GameManager::getGame<PlatformerGame>()->stop();
        return;
    }

    if (event->getTranslateTo().getX() >= camera->getPosition().getX()) {
        camera->setPosition(
                Vector2(event->getTranslateTo().getX(), 0));
    }
    if (event->isCanceled()) {
        currentImage = idleSprite->getImage();
        Logger::logMessage("setIdle");
    }
}

void PlatformerPlayerEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    auto side = event->getRectangleCollidedSide();
    if (side == Util::Game::BOTTOM_SIDE) {
        canJump = true;
    }

    auto game = Util::Game::GameManager::getGame<PlatformerGame>();
    auto scene = game->getScene();

    auto collidedWithTag = event->getCollidedWith().getTag();
    if (collidedWithTag == "BrickBlock") {
        if (side == Util::Game::TOP_SIDE) {
            scene->removeEntity(&event->getCollidedWith());
            Logger::logMessage("Mario destroyed Block");
        }
    } else if (collidedWithTag == "Mushroom") {
        Logger::logMessage("Mushroom collected");

        setBig(true);
        scene->removeEntity(&event->getCollidedWith());
    } else if (collidedWithTag == "Ninja") {
        if (side == Util::Game::BOTTOM_SIDE) {
            Logger::logMessage("Player killed Ninja");
        } else {
            if (big) {
                setBig(false);
            } else {
                Logger::logMessage("Player was killed by Ninja");
                game->stop();
                return;
            }
        }
        scene->removeEntity(&event->getCollidedWith());
        game->spawnNinja(position + Vector2(1.5, 0.1), groundY);
    } else if (collidedWithTag == "Chest"){
        Logger::logMessage("Player finished Level by collecting chest!");
        game->nextLevel();
        return;
    }
}

void PlatformerPlayerEntity::moveRight() {
    translateX(speed);
    directionLeft = false;
    currentImage = runAnimation->getNextSprite().getImage();
}

void PlatformerPlayerEntity::moveLeft() {
    translateX(-speed);
    directionLeft = true;
    currentImage = runAnimation->getNextSprite().getImage();
}

void PlatformerPlayerEntity::jump() {
    if (canJump) {
        translateY(jumpSpeed);
        canJump = false;
    }
}

void PlatformerPlayerEntity::onUpdate(double dt) {
}

void PlatformerPlayerEntity::setBig(bool val) {
    big = val;
    //collider->setHeight(height * (big ? 2 : 1));
}
