cmake_minimum_required(VERSION 3.14)

target_sources(lib.util PUBLIC
        ${HHUOS_SRC_DIR}/lib/util/game/entity/Entity.cpp)

add_subdirectory(component)
add_subdirectory(collider)
add_subdirectory(event)