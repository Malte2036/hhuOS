//
// Created by malte on 05.12.22.
//

#include "FoodEntity.h"
#include "lib/util/log/Logger.h"
#include "lib/util/math/Random.h"

auto random = Util::Math::Random(12221);

FoodEntity::FoodEntity(const Vector2 &position, double size, SnakeGameData *gameData) : Entity("FoodEntity", position),
                                                                                        size{size},
                                                                                        gameData{gameData} {}

void FoodEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.setColor(Util::Graphic::Colors::YELLOW);
    graphics.drawSquare(getPosition(), size);
}

void FoodEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

Util::Game::RectangleCollider FoodEntity::getCollider() const {
    return Util::Game::RectangleCollider(getPosition(), size, size);
}

void FoodEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {
    if (event->getCollidedWithTag() == "SnakeEntity") {
        Logger::logMessage("FoodEntity collided with SnakeEntity!");
        setPosition(Vector2((random.nextRandomNumber() * 2) - 1, (random.nextRandomNumber() * 2) - 1));

        gameData->score = gameData->score + 1;
    }
}

