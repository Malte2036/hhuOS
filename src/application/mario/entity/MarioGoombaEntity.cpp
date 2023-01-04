//
// Created by malte on 03.01.23.
//

#include "MarioGoombaEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/mario/MarioGame.h"
#include "lib/util/log/Logger.h"
#include "lib/util/game/entity/component/GravityComponent.h"

MarioGoombaEntity::MarioGoombaEntity(const Vector2 &position) : Util::Game::Entity("Goomba", position) {
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/goomba_run_1.bmp"),
                    new Util::Game::Sprite(
                            "/initrd/goomba_run_2.bmp")});
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);

    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioGoombaEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    graphics.drawRectangle(position, getCollider()->getHeight(), getCollider()->getWidth());
}

void MarioGoombaEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioGoombaEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

    auto collidedWithSide = event->getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void MarioGoombaEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if (event->getTranslateTo().getY() <= groundY) {
        event->setCanceled(true);
    }
}
