//
// Created by Malte Sehmer on 05.12.22.
//

#include "FoodEntity.h"
#include "lib/util/log/Logger.h"
#include "lib/util/math/Random.h"
#include "lib/util/game/GameManager.h"

auto random = Util::Math::Random(12221);

FoodEntity::FoodEntity(const Vector2 &position, double size) : Entity("FoodEntity", position),
                                                               size{size} {
    collider = new Util::Game::RectangleCollider(getPosition(), size, size, Util::Game::STATIC_COLLIDER);
}

void FoodEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(Util::Graphic::Colors::YELLOW);
    graphics.drawSquare(getPosition(), size);
}

void FoodEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

void FoodEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    if (event.getCollidedWith().getTag() == "SnakeEntity") {
        Logger::logMessage("FoodEntity collided with SnakeEntity!");

        auto game = Util::Game::GameManager::getGame<SnakeGame>();
        auto scene = game->getScene();

        game->setSnakeGameData({game->getSnakeGameData().score + 1});

        scene->addEntity(
                new FoodEntity(Vector2((random.nextRandomNumber() * 2) - 1, (random.nextRandomNumber() * 2) - 1),
                               size));
        scene->removeEntity(this);
    }
}

void FoodEntity::onUpdate(double dt) {

}

