//
// Created by Malte Sehmer on 09.01.23.
//

#ifndef HHUOS_POLYGONDEMOSCENE_H
#define HHUOS_POLYGONDEMOSCENE_H


#include "lib/util/game/scene/Scene.h"
#include "DemoPolygonFactory.h"
#include "lib/util/data/ArrayListBlockingQueue.h"

class PolygonDemoScene :public Util::Game::Scene, public Util::Game::KeyListener{


public:
    PolygonDemoScene(uint32_t count);

protected:
    void init() override;

    void onUpdate(double dt) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

public:
    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

    const uint32_t count;

    DemoPolygonFactory factory;
    Util::Data::ArrayListBlockingQueue<DemoPolygon *> polygons;
};


#endif //HHUOS_POLYGONDEMOSCENE_H
