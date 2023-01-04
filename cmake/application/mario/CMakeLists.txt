cmake_minimum_required(VERSION 3.14)

project(mario)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${HHUOS_SRC_DIR}/application/mario/mario.cpp
        ${HHUOS_SRC_DIR}/application/mario/MarioGame.cpp
        ${HHUOS_SRC_DIR}/application/mario/entity/MarioEntity.cpp
        ${HHUOS_SRC_DIR}/application/mario/entity/MarioGoombaEntity.cpp
        ${HHUOS_SRC_DIR}/application/mario/entity/MarioMushroomEntity.cpp
        ${HHUOS_SRC_DIR}/application/mario/block/MarioBrickBlockEntity.cpp
        ${HHUOS_SRC_DIR}/application/mario/block/MarioSolidBlockEntity.cpp
        ${HHUOS_SRC_DIR}/application/mario/block/MarioItemBlockEntity.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} lib.crt0 lib.user)