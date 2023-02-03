//
// Created by Malte Sehmer on 09.01.23.
//

#include "PlatformerBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"

PlatformerBlockEntity::PlatformerBlockEntity(const Util::Memory::String &tag, const Vector2 &position,
                                             const Util::Memory::String &spriteBmpPath, int countX, int countY)
        : Util::Game::Entity(tag,
                             position), countX{countX}, countY{countY} {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    sprite = new Util::Game::Sprite(spriteBmpPath, size, size);
    collider = new Util::Game::RectangleCollider(position, size * countY, size * countX, Util::Game::STATIC_COLLIDER);

}

void PlatformerBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    for (int y = 0; y < countY; ++y) {
        for (int x = 0; x < countX; ++x) {
            graphics.drawImage(Vector2(position.getX() + x * size, position.getY() + y * size), *sprite->getImage());
        }
    }
    //graphics.setColor(Util::Graphic::Colors::RED);
    //graphics.drawRectangle(position, size * countY, size * countX);
}

void PlatformerBlockEntity::onUpdate(double dt) {

}

void PlatformerBlockEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

void PlatformerBlockEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {

}