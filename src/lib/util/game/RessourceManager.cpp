//
// Created by Malte Sehmer on 06.02.23.
//

#include "RessourceManager.h"

namespace Util::Game {
    void RessourceManager::addImage(const Util::Memory::String &key, Util::File::Image::Image *image) {
        if (hasImage(key)) {
            imagesCount.put(key, imagesCount.get(key) + 1);
        } else {
            imagesCount.put(key, 1);
        }
        images.put(key, image);
    }

    bool RessourceManager::hasImage(const Util::Memory::String &key) {
        return images.containsKey(key);
    }

    File::Image::Image *RessourceManager::getImage(const Memory::String &key) {
        imagesCount.put(key, imagesCount.get(key) + 1);
        return images.get(key);
    }

    void RessourceManager::deleteImage(const Memory::String &key) {
        auto count = imagesCount.get(key) - 1;
        if (count > 0) {
            imagesCount.put(key, count);
            return;
        }
        imagesCount.put(key, 0);

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