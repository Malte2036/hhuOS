cmake_minimum_required(VERSION 3.14)

target_sources(lib.util PUBLIC
        ${HHUOS_SRC_DIR}/lib/util/game/entity/event/Event.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/entity/event/CancelableEvent.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/entity/event/CollisionEvent.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/entity/event/TranslateEvent.cpp)
