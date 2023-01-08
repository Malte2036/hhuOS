cmake_minimum_required(VERSION 3.14)

project(platformer)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${HHUOS_SRC_DIR}/application/platformer/platformer.cpp
        ${HHUOS_SRC_DIR}/application/platformer/PlatformerGame.cpp
        ${HHUOS_SRC_DIR}/application/platformer/entity/PlatformerPlayerEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/entity/PlatformerNinjaEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/entity/PlatformerMushroomEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/block/PlatformerBrickBlockEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/block/PlatformerSolidBlockEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/block/PlatformerItemBlockEntity.cpp
        ${HHUOS_SRC_DIR}/application/platformer/text/PlatformerScoreText.cpp
        ${HHUOS_SRC_DIR}/application/platformer/scene/PlatformerScene1.cpp
        ${HHUOS_SRC_DIR}/application/platformer/scene/PlatformerScene2.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} lib.crt0 lib.user)