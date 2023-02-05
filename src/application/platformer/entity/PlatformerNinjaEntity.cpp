//
// Created by Malte Sehmer on 03.01.23.
//

#include "PlatformerNinjaEntity.h"
#include "lib/util/game/GameManager.h"
#include "lib/util/game/entity/component/GravityComponent.h"
#include "application/platformer/PlatformerGame.h"
#include "lib/util/log/Logger.h"

PlatformerNinjaEntity::PlatformerNinjaEntity(const Vector2 &position) : Util::Game::Entity("Ninja",
                                                                                           position) {
    runAnimation = new Util::Game::SpriteAnimation(
            {
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_1.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_2.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_3.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_4.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_5.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_6.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_7.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_8.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_9.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_10.bmp", width, height),
                    new Util::Game::Sprite(
                            "/initrd/game/platformer/ninja/run/ninja_run_11.bmp", width, height)});
    collider = new Util::Game::RectangleCollider(position, height, width, Util::Game::DYNAMIC_COLLIDER);

    currentImage = runAnimation->getNextSprite().getImage();
}

PlatformerNinjaEntity::~PlatformerNinjaEntity() {
    delete runAnimation;
}

void PlatformerNinjaEntity::draw(Util::Game::Graphics2D &graphics) const {
    graphics.drawImage(position, *currentImage, directionLeft);
    /*if (collider != nullptr)
        graphics.drawRectangle(position, collider->getHeight(), collider->getWidth());*/
}

auto i = 1;

void PlatformerNinjaEntity::onUpdate(double dt) {
    translateX(speed * (directionLeft ? -1 : 1));
    if (i == 0 && runAnimation != nullptr) {
        currentImage = runAnimation->getNextSprite().getImage();
    }
    i = (i + 1) % 3;
}

void PlatformerNinjaEntity::onCollisionEvent(Util::Game::CollisionEvent &event) {
    auto tag = event.getCollidedWith().getTag();
    if (tag == "PlayerProjectile") {
        Util::Game::GameManager::getGame<PlatformerGame>()->getScene()->removeEntity(this);
        return;
    }

    auto collidedWithSide = event.getRectangleCollidedSide();
    if (collidedWithSide == Util::Game::LEFT_SIDE) {
        directionLeft = false;
    } else if (collidedWithSide == Util::Game::RIGHT_SIDE) {
        directionLeft = true;
    }
}

void PlatformerNinjaEntity::onTranslateEvent(Util::Game::TranslateEvent &event) {
    if (event.getTranslateTo().getY() < -2) {
        Logger::logMessage("Remove Ninja");
        Util::Game::GameManager::getGame<PlatformerGame>()->getScene()->removeEntity(this);
        return;
    }
}

void PlatformerNinjaEntity::init() {

}
