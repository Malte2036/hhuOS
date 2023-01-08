//
// Created by malte on 05.12.22.
//

#include "SnakeEntity.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/log/Logger.h"
#include "application/snake/SnakeGame.h"

SnakeEntity::SnakeEntity(const Vector2 &position, double size, Util::Graphic::Color color, DirectionType direction,
                         double speed)
        : Util::Game::Entity("SnakeEntity", position), color{color}, direction{direction}, size{size}, speed{speed} {
    collider = new Util::Game::RectangleCollider(getPosition(), size, size, Util::Game::STATIC_COLLIDER);
}


void SnakeEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(color);
    graphics.drawSquare(getPosition(), size);
}


DirectionType SnakeEntity::getDirection() {
    return direction;
}

void SnakeEntity::setDirection(DirectionType directionType) {
    direction = directionType;
}

void SnakeEntity::setColor(Util::Graphic::Color value) {
    color = value;
}

void SnakeEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {
    auto transformTo = event->getTranslateTo();
    if (transformTo.getX() > 1 || transformTo.getX() < (-1 - size)
        || transformTo.getY() > (1 - size) || transformTo.getY() < -1) {
        event->setCanceled(true);
        setDirection(none);

        Logger::logMessage("TransformEvent cancelled");

        Util::Game::GameManager::getGame<SnakeGame>()->stop();
    }
}

void SnakeEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    Logger::logMessage("Snake collided!");
}

void SnakeEntity::move() {
    switch (direction) {
        case right:
            translate(Vector2(speed, 0));
            return;
        case left:
            translate(Vector2(-speed, 0));
            return;
        case up:
            translate(Vector2(0, speed));
            return;
        case down:
            translate(Vector2(0, -speed));
            return;
    }
}

void SnakeEntity::onUpdate(double dt) {

}


