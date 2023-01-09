//
// Created by malte on 09.01.23.
//

#include "PlatformerBlockEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"

PlatformerBlockEntity::PlatformerBlockEntity(const Util::Memory::String &tag, const Vector2 &position,
                                             const Util::Memory::String &spriteBmpPath) : Util::Game::Entity(tag,
                                                                                                             position) {
    auto size = Util::Game::GameManager::getGame<PlatformerGame>()->getBlockSize();
    sprite = new Util::Game::Sprite(spriteBmpPath, size, size);
    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::STATIC_COLLIDER);

}

void PlatformerBlockEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
}

void PlatformerBlockEntity::onUpdate(double dt) {

}

void PlatformerBlockEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerBlockEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}