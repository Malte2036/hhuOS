//
// Created by Malte Sehmer on 20.12.22.
//

#ifndef HHUOS_COMPONENT_H
#define HHUOS_COMPONENT_H

#include "lib/util/game/entity/Entity.h"

namespace Util::Game {
    class Component {
        friend Entity;
    public:
        Component() = default;

        /**
         * Copy Constructor.
        */
        Component(const Component &other) = delete;

        /**
         * Assignment operator.
         */
        Component &operator=(const Component &other) = delete;

        /**
        * Destructor.
        */
        virtual ~Component() = default;

        Memory::String getType();

    protected:
        virtual void update(double dt) = 0;

        void setEntity(Entity *pointer);

        Entity *getEntity();

    private:
        Memory::String type;

        Entity *entity = nullptr;
    };
}


#endif //HHUOS_COMPONENT_H
