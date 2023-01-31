//
// Created by Malte Sehmer on 09.01.23.
//

#ifndef HHUOS_CUBEDEMOSCENE_H
#define HHUOS_CUBEDEMOSCENE_H

#include "lib/util/game/scene/Scene.h"
#include "Cube.h"

class CubeDemoScene : public Util::Game::Scene, public Util::Game::KeyListener {

public:
    explicit CubeDemoScene(int32_t speed = 10);

private:
    void init() override;

    void onUpdate(double dt) override;

    void drawInitialBackground(Util::Game::Graphics2D &graphics) override;

public:
    void keyPressed(Util::Io::Key key) override;

    void keyReleased(Util::Io::Key key) override;

private:

    static const constexpr uint32_t NUM_CUBES = 4;
    Cube *cubes[NUM_CUBES] = {new Cube(-0.5, 0.5, 0.25), new Cube(0.5, 0.5, 0.25), new Cube(0.5, -0.5, 0.25), new Cube(-0.5, -0.5, 0.25)};

    int32_t speed;

    // Rotation angles
    static const constexpr double ANGLE_X = 0.01;
    static const constexpr double ANGLE_Y = 0.0075;
    static const constexpr double ANGLE_Z = 0.005;
};


#endif //HHUOS_CUBEDEMOSCENE_H
