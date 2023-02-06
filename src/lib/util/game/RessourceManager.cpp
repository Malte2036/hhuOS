//
// Created by Malte Sehmer on 06.02.23.
//

#include "RessourceManager.h"
#include "lib/util/log/Logger.h"

namespace Util::Game {
    void RessourceManager::addImage(const Util::Memory::String &key, Util::File::Image::Image *image) {
        images.put(key, image);
        Logger::logMessage(key);
    }

    bool RessourceManager::hasImage(const Util::Memory::String &key) {
        return images.containsKey(key);
    }

    File::Image::Image *RessourceManager::getImage(const Memory::String &key) {
        return images.get(key);
    }

    void RessourceManager::deleteImage(const Memory::String &key) {
        auto image = images.get(key);
        delete image;

        images.remove(key);
    }

    void RessourceManager::deleteAllImages() {
        for (auto *image: images.values()) {
            delete image;
        }
        images.clear();
    }
}