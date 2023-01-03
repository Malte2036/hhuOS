//
// Created by malte on 03.01.23.
//

#include "MarioGoombaEntity.h"
#include "lib/util/game/GameManager.h"
#include "MarioGame.h"
#include "lib/util/log/Logger.h"
#include "lib/util/game/entity/component/GravityComponent.h"

MarioGoombaEntity::MarioGoombaEntity(const Vector2 &position) : Util::Game::Entity("Goomba", position) {
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/goomba_run_1.bmp"),
                    new Util::Game::Sprite(
                            "/initrd/goomba_run_2.bmp")});
    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioGoombaEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage);
    graphics.drawRectangle(position, getCollider().getHeight(), getCollider().getWidth());
}

void MarioGoombaEntity::onUpdate(double dt) {
    translateX(-speed);
    currentImage = runAnimation->getNextSprite().getImage();
}

void MarioGoombaEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWith()->getTag() == "Player") {
        Logger::logMessage("collided");
        auto side = event->getRectangleCollidedSide();
        if (side == Util::Game::TOP_SIDE) {
            Logger::logMessage("Goomba was killed by Player");
            auto game = Util::Game::GameManager::getGame<MarioGame>();
            game->spawnGoomba(position + Vector2(1, 0.25));

            game->removeEntity(this);
            return;
        }
        Logger::logMessage("Player was killed by Goomba");
        Util::Game::GameManager::getGame<MarioGame>()->stop();
        return;
    }
}

void MarioGoombaEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    if (event->getTranslateTo().getY() <= groundY) {
        event->setCanceled(true);
    }
}

Util::Game::RectangleCollider MarioGoombaEntity::getCollider() const {
    return Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);
}

