//
// Created by Malte Sehmer on 04.02.23.
//

#include "PlatformerPlayerProjectileEntity.h"
#include "lib/util/game/GameManager.h"
#include "application/platformer/PlatformerGame.h"

PlatformerPlayerProjectileEntity::PlatformerPlayerProjectileEntity(const Vector2 &position, const Vector2 &direction)
        : Util::Game::Entity(
        "PlayerProjectile",
        position),
          direction{direction},
          startPosition{position} {
    sprite = new Util::Game::Sprite("/initrd/game/platformer/player/projectile.bmp", size * 3, size);

    collider = new Util::Game::RectangleCollider(position, size, size, Util::Game::DYNAMIC_COLLIDER);
}

void PlatformerPlayerProjectileEntity::init() {

}

PlatformerPlayerProjectileEntity::~PlatformerPlayerProjectileEntity() {
    delete sprite;
}


void PlatformerPlayerProjectileEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(Vector2(position.getX() + (direction.getX() > 0 ? -1 : 1) * size * 2, position.getY()),
                       *sprite->getImage(), direction.getX() > 0);
}

void PlatformerPlayerProjectileEntity::onUpdate(double dt) {
    if ((position - startPosition).length() > 2) {
        Util::Game::GameManager::getGame<PlatformerGame>()->getScene()->removeEntity(this);
        return;
    }
    translate(direction);
}

void PlatformerPlayerProjectileEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {

}

void PlatformerPlayerProjectileEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    auto tag = event.getCollidedWith().getTag();
    if (tag == "Player")
        return;

    Util::Game::GameManager::getGame<PlatformerGame>()->getScene()->removeEntity(this);
}
