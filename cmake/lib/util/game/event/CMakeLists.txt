cmake_minimum_required(VERSION 3.14)

target_sources(lib.util PUBLIC
        ${HHUOS_SRC_DIR}/lib/util/game/event/Event.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/event/CancelableEvent.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/event/CollisionEvent.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/event/TransformEvent.cpp)
