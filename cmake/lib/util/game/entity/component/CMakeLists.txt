cmake_minimum_required(VERSION 3.14)

target_sources(lib.util PUBLIC
        ${HHUOS_SRC_DIR}/lib/util/game/entity/component/Component.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/entity/component/GravityComponent.cpp
        ${HHUOS_SRC_DIR}/lib/util/game/entity/component/LinearMovementComponent.cpp)
