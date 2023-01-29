//
// Created by malte on 09.01.23.
//

#include "PolygonDemoScene.h"
#include "lib/util/game/GameManager.h"
#include "PolygonDemo.h"

PolygonDemoScene::PolygonDemoScene(uint32_t count) : count{count} {

}

void PolygonDemoScene::init() {
    for (uint32_t i = 0; i < count; i++) {
        auto *polygon = factory.createPolygon();
        polygons.offer(polygon);
        addObject(polygon);
    }

    setKeyListener(*this);
}

void PolygonDemoScene::drawInitialBackground(Util::Game::Graphics2D &graphics) {

}

void PolygonDemoScene::onUpdate(double dt) {
    for (auto &polygon : polygons) {
        polygon->update(dt);
    }
}

void PolygonDemoScene::keyPressed(Util::Io::Key key) {
    switch (key.getAscii()) {
        case '+': {
            auto *polygon = factory.createPolygon();
            polygons.offer(polygon);
            addObject(polygon);
            break;
        }
        case '-': {
            if (polygons.size() > 0) {
                removeObject(polygons.poll());
            }
            break;
        }
        default:
            Util::Game::GameManager::getGame<PolygonDemo>()->stop();
    }
}

void PolygonDemoScene::keyReleased(Util::Io::Key key) {

}
