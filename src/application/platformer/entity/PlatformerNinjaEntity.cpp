//
// Created by malte on 03.01.23.
//

#include "PlatformerNinjaEntity.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/GravityComponent.h"

PlatformerNinjaEntity::PlatformerNinjaEntity(const Vector2 &position, double groundY) : Util::Game::Entity("Ninja",
                                                                                                           position),
                                                                                        groundY{groundY} {
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_1.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_2.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_3.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_4.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_5.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_6.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_7.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_8.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_9.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_10.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_11.bmp", width, height)});
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);

    currentImage = runAnimation->getNextSprite().getImage();
}

void PlatformerNinjaEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    //graphics.drawRectangle(position, getCollider()->getHeight(), getCollider()->getWidth());
}

auto i = 1;

void PlatformerNinjaEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
    if (i == 0) {
        currentImage = runAnimation->getNextSprite().getImage();
    }
    i = (i + 1) % 3;
}

void PlatformerNinjaEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

    auto collidedWithSide = event->getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void PlatformerNinjaEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if (event->getTranslateTo().getY() <= groundY) {
        event->setCanceled(true);
    }
}
