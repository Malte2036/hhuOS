//
// Created by Malte Sehmer on 31.01.23.
//

#include "PlatformerGrassBlockEntity.h"

PlatformerGrassBlockEntity::PlatformerGrassBlockEntity(const Vector2 &position, int countX) : PlatformerBlockEntity(
        "GrassBlock", position, "/initrd/game/platformer/ground/ground_grass_middle.bmp", countX) {

}
