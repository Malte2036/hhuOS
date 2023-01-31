//
// Created by Malte Sehmer on 07.12.22.
//

#ifndef HHUOS_PLATFORMERITEMBLOCKENTITY_H
#define HHUOS_PLATFORMERITEMBLOCKENTITY_H


#include "PlatformerBlockEntity.h"

class PlatformerItemBlockEntity : public PlatformerBlockEntity {
public:
    explicit PlatformerItemBlockEntity(const Vector2 &position);

private:
    void onCollisionEvent(Util::Game::CollisionEvent *event) override;
};


#endif //HHUOS_PLATFORMERITEMBLOCKENTITY_H
