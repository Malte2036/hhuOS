//
// Created by Malte Sehmer on 01.02.23.
//

#ifndef HHUOS_PLATFORMERLAVABLOCKENTITY_H
#define HHUOS_PLATFORMERLAVABLOCKENTITY_H


#include "PlatformerBlockEntity.h"

class PlatformerLavaBlockEntity : public PlatformerBlockEntity {
public:
    explicit PlatformerLavaBlockEntity(const Vector2 &position, int countX = 1, int countY = 1);

private:

    void draw(Util::Game::Graphics2D &graphics) const override;

    void onUpdate(double dt) override;

    int animateIndex = 0;
    bool flip = false;
};


#endif //HHUOS_PLATFORMERLAVABLOCKENTITY_H
