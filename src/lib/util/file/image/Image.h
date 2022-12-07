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
        Image() {
            width = 100;
            height = 300;
            pixelBuf = new Graphic::Color[width * height];

            auto color = Graphic::Colors::GREEN;
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    pixelBuf[x + y] = color;
                }

            }
        };

        void draw(Util::Graphic::PixelDrawer drawer, uint16_t x, uint16_t y) const;

        Graphic::Color *pixelBuf = nullptr;

        uint32_t width = 0;
        uint32_t height = 0;
        uint8_t depth = 0;
    };
}


#endif //HHUOS_IMAGE_H
