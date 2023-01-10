//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_PLATFORMERBRICKBLOCKENTITY_H
#define HHUOS_PLATFORMERBRICKBLOCKENTITY_H

#include "PlatformerBlockEntity.h"

class PlatformerBrickBlockEntity : public PlatformerBlockEntity {
public:
    explicit PlatformerBrickBlockEntity(const Vector2 &position, int countX = 1);
};


#endif //HHUOS_PLATFORMERBRICKBLOCKENTITY_H
