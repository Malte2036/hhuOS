cmake_minimum_required(VERSION 3.14)

target_sources(lib.util PUBLIC
        ${HHUOS_SRC_DIR}/lib/util/game/collider/Collider.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/collider/RectangleCollider.cpp)
