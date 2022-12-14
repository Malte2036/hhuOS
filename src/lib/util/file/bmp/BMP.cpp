//
// Created by malte on 12.12.22.
//

#include "BMP.h"
#include "lib/util/math/Math.h"

namespace Util::File::Image {

    BMP::BMP(int width, int height, Graphic::Color *pixelBuff) : Image(width, height, pixelBuff) {

    }

    BMP* BMP::fromFile(uint8_t *buffer) {
        auto *header = reinterpret_cast<Header *>(buffer);

        auto dataOffset = headerDataToInt(header->data_offset, 4);
        auto bitmapWidth = headerDataToInt(header->bitmap_width, 4);
        auto bitmapHeight = headerDataToInt(header->bitmap_height, 4);
        auto bitmapBitsPerPixel = headerDataToInt(header->bitmap_bits_per_pixel, 2);

        auto bitmap = buffer + dataOffset;

        auto pixelLength = bitmapBitsPerPixel / 8;

        auto* pixelBuf = new Graphic::Color[bitmapWidth * bitmapHeight];

        for (auto y = bitmapHeight - 1; y >= 0; y--) {
            for (auto x = 0; x < bitmapWidth; x++) {
                uint32_t pos = (y * bitmapWidth * pixelLength) + (pixelLength * x);

                auto blue = *(bitmap + pos);
                auto green = *(bitmap + pos + 1);
                auto red = *(bitmap + pos + 2);
                auto color =  Graphic::Color(red, green, blue);
                pixelBuf[(y * bitmapWidth) + x] = color;
            }

        }

        return new BMP(bitmapWidth, bitmapHeight, pixelBuf);
    }

    int32_t BMP::headerDataToInt(const uint8_t *buffer, int size) {
        int32_t res = 0;
        for (auto i = 0; i < size; i++) {
            res += *(buffer + i) * (int) Math::Math::pow(256, i);
        }
        return res;
    }
}