//
// Created by malte on 20.12.22.
//

#include "Component.h"

namespace Util::Game {
    void Component::setEntity(Entity *pointer) {
        entity = pointer;
    }

    Entity *Component::getEntity() {
        return entity;
    }

    Memory::String Component::getType() {
        return type;
    }
}