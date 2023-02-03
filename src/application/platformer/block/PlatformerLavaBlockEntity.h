//
// Created by Malte Sehmer on 01.02.23.
//

#ifndef HHUOS_PLATFORMERLAVABLOCKENTITY_H
#define HHUOS_PLATFORMERLAVABLOCKENTITY_H


#include "PlatformerBlockEntity.h"

class PlatformerLavaBlockEntity : public PlatformerBlockEntity {
public:
    PlatformerLavaBlockEntity(const Vector2 &position, int countX = 1, int countY = 1);
};


#endif //HHUOS_PLATFORMERLAVABLOCKENTITY_H
