//
// Created by Malte Sehmer on 01.01.23.
//

#include "SpriteAnimation.h"

namespace Util::Game {

    SpriteAnimation::SpriteAnimation(const Data::Array<Sprite *> &allSprites) :
            sprites{allSprites} {
    }

    Sprite SpriteAnimation::getNextSprite() {
        frame++;
        if (frame >= sprites.length()) {
            frame = 0;
        }
        return *sprites[frame];
    }

    SpriteAnimation::~SpriteAnimation() {
        for (const auto *sprite: sprites) {
            delete sprite;
        }
    }
}
