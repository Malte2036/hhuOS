//
// Created by malte on 01.01.23.
//

#ifndef HHUOS_SPRITEANIMATION_H
#define HHUOS_SPRITEANIMATION_H


#include "Sprite.h"

namespace Util::Game {
    class SpriteAnimation {

    public:
        explicit SpriteAnimation(const Data::Array<Sprite *> &allSprites);

        /**
         * Copy Constructor.
        */
        SpriteAnimation(const SpriteAnimation &other) = delete;

        /**
         * Assignment operator.
         */
        SpriteAnimation &operator=(const SpriteAnimation &other) = delete;

        /**
         * Destructor.
         */
        virtual ~SpriteAnimation();

        Sprite getNextSprite();

    private:
        int frame = 0;
        Data::Array<Sprite *> sprites;
    };
}

#endif //HHUOS_SPRITEANIMATION_H
