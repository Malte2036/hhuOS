//
// Created by malte on 12.12.22.
//

#ifndef HHUOS_BMP_H
#define HHUOS_BMP_H


#include "lib/util/file/image/Image.h"

namespace Util::File::Image {

    class BMP : public Image {
    public:
        static BMP *fromFile(const Memory::String& filename);

        struct Header {
            char signature[2];
            uint8_t size[4];
            uint8_t reserved[4];
            uint8_t data_offset[4];
            uint8_t dib_header_size[4];
            uint8_t bitmap_width[4];
            uint8_t bitmap_height[4];
            uint8_t bitmap_count_color_planes[2];
            uint8_t bitmap_bits_per_pixel[2];
        };

    private:
        BMP(int width, int height, Graphic::Color *pixelBuff);

        static uint8_t *getFileBuffer(const Memory::String& filename);
    };
}

#endif //HHUOS_BMP_H
