//
// Created by Malte Sehmer on 07.12.22.
//

#include "PlatformerSolidBlockEntity.h"
#include "lib/util/game/GameManager.h"

PlatformerSolidBlockEntity::PlatformerSolidBlockEntity(const Vector2 &position)
        : PlatformerBlockEntity("SolidBlock", position, "/initrd/game/platformer/block/block_solid.bmp") {
}
