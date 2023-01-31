//
// Created by Malte Sehmer on 09.01.23.
//

#include "PlatformerBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"

PlatformerBlockEntity::PlatformerBlockEntity(const Util::Memory::String &tag, const Vector2 &position,
                                             const Util::Memory::String &spriteBmpPath, int countX)
        : Util::Game::Entity(tag,
                             position), countX{countX} {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    sprite = new Util::Game::Sprite(spriteBmpPath, size, size);
    collider = new Util::Game::RectangleCollider(position, size, size * countX, Util::Game::STATIC_COLLIDER);

}

void PlatformerBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    for (int i = 0; i < countX; ++i) {
        graphics.drawImage(Vector2(position.getX() + i * size, position.getY()), *sprite->getImage());
    }
    //graphics.setColor(Util::Graphic::Colors::RED);
    //graphics.drawRectangle(position, size, size * countX);
}

void PlatformerBlockEntity::onUpdate(double dt) {

}

void PlatformerBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}