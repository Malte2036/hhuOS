//
// Created by malte on 16.12.22.
//

#ifndef HHUOS_SPRITE_H
#define HHUOS_SPRITE_H


#include "lib/util/file/image/Image.h"
#include "lib/util/memory/String.h"

namespace Util::Game {
    class Sprite {
    public:
        explicit Sprite(const Memory::String& filename, double width, double height);

        /**
         * Copy Constructor.
        */
        Sprite(const Sprite &other) = default;

        /**
         * Assignment operator.
         */
        Sprite &operator=(const Sprite &other) = delete;

        [[nodiscard]] File::Image::Image* getImage() const;


    private:
        Util::File::Image::Image *image = nullptr;
    };
}


#endif //HHUOS_SPRITE_H
