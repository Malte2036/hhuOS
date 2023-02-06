//
// Created by Malte Sehmer on 06.02.23.
//

#ifndef HHUOS_RESSOURCEMANAGER_H
#define HHUOS_RESSOURCEMANAGER_H

#include "lib/util/file/image/Image.h"
#include "lib/util/data/HashMap.h"

namespace Util::Game {

    class RessourceManager {
    public:
        static void addImage(const Memory::String &key, File::Image::Image *image);

        static bool hasImage(const Util::Memory::String &key);

        static File::Image::Image *getImage(const Util::Memory::String &key);

        static void deleteImage(const Util::Memory::String &key);

        static void deleteAllImages();

    private:
        inline static auto images = Data::HashMap<Memory::String, File::Image::Image *>();
    };
}


#endif //HHUOS_RESSOURCEMANAGER_H
