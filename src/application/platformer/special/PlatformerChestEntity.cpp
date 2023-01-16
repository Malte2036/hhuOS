//
// Created by malte on 10.01.23.
//

#include "PlatformerChestEntity.h"
#include "lib/util/game/Polygon.h"

PlatformerChestEntity::PlatformerChestEntity(const Vector2 &position) : Util::Game::Entity("Chest", position) {
    sprite = new Util::Game::Sprite("initrd/game/platformer/special/chest.bmp", width, height);
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::STATIC_COLLIDER);

    auto vertices = new Util::Data::Array<Vector2>(
            {position, position + Vector2(0, height), position + Vector2(width, height), position + Vector2(width, 0)});
    auto polygon = new Util::Game::Polygon(*vertices);
    polygonCollider = new Util::Game::PolygonCollider(*polygon, Util::Game::STATIC_COLLIDER);

}

void PlatformerChestEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *sprite->getImage());
    graphics.setColor(Util::Graphic::Colors::RED);
    graphics.drawPolygon(polygonCollider->getPolygon().getVertices());
}

void PlatformerChestEntity::onUpdate(double dt) {

}

void PlatformerChestEntity::onTranslateEvent(Util::Game::TranslateEvent *event) {

}

void PlatformerChestEntity::onCollisionEvent(Util::Game::CollisionEvent *event) {

}

