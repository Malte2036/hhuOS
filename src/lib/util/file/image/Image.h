//
// Created by malte on 07.12.22.
//

#ifndef HHUOS_IMAGE_H
#define HHUOS_IMAGE_H


#include <cstdint>

#include "lib/util/graphic/Color.h"
#include "lib/util/graphic/PixelDrawer.h"

namespace Util::File::Image {
    class Image {
    public:
        Image(int width, int height, Graphic::Color *pixelBuff);

        ~Image();

        Graphic::Color *getPixelBuffer() const;

        int getWidth() const;

        int getHeight() const;

    private:
        Graphic::Color *pixelBuf = nullptr;

        const int width;
        const int height;
    };
}


#endif //HHUOS_IMAGE_H
