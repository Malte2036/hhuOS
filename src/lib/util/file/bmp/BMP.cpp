//
// Created by Malte Sehmer on 12.12.22.
//

#include "BMP.h"
#include "lib/util/math/Math.h"
#include "lib/util/stream/FileInputStream.h"
#include "lib/util/file/File.h"

namespace Util::File::Image {

    BMP::BMP(int width, int height, Graphic::Color *pixelBuff) : Image(width, height, pixelBuff) {

    }

    BMP *BMP::fromFile(const Memory::String &filename) {
        auto buffer = getFileBuffer(filename);

        auto *header = reinterpret_cast<Header *>(buffer);

        auto dataOffset = (*(header->data_offset + 3) << 24) | (*(header->data_offset + 2) << 16) |
                          (*(header->data_offset + 1) << 8) | *header->data_offset;
        auto bitmapWidth = (*(header->bitmap_width + 3) << 24) | (*(header->bitmap_width + 2) << 16) |
                           (*(header->bitmap_width + 1) << 8) | *header->bitmap_width;
        auto bitmapHeight = (*(header->bitmap_height + 3) << 24) | (*(header->bitmap_height + 2) << 16) |
                            (*(header->bitmap_height + 1) << 8) | *header->bitmap_height;
        auto bitmapBitsPerPixel = (*(header->bitmap_bits_per_pixel + 1) << 8) | *header->bitmap_bits_per_pixel;

        auto bitmap = buffer + dataOffset;

        auto pixelLength = bitmapBitsPerPixel / 8;

        if (pixelLength != 3 && pixelLength != 4) {
            Exception::throwException(Exception::UNSUPPORTED_OPERATION, "BMP: Unsupported pixel length");
        }

        auto *pixelBuf = new Graphic::Color[bitmapWidth * bitmapHeight];

        for (auto y = bitmapHeight - 1; y >= 0; y--) {
            for (auto x = 0; x < bitmapWidth; x++) {
                uint32_t pos = (y * bitmapWidth * pixelLength) + (pixelLength * x);

                auto blue = *(bitmap + pos);
                auto green = *(bitmap + pos + 1);
                auto red = *(bitmap + pos + 2);
                auto alpha = 0;
                if (pixelLength == 4) {
                    alpha = *(bitmap + pos + 3);
                }
                auto color = Graphic::Color(red, green, blue, alpha);
                pixelBuf[(y * bitmapWidth) + x] = color;
            }

        }

        delete bitmap;

        return new BMP(bitmapWidth, bitmapHeight, pixelBuf);
    }

    uint8_t *BMP::getFileBuffer(const Memory::String &filename) {
        auto file = Util::File::File(filename);
        auto *buffer = new uint8_t[file.getLength()];
        auto binaryStream = Util::Stream::FileInputStream(file);
        binaryStream.read(buffer, 0, file.getLength());

        return buffer;
    }
}