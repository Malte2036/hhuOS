cmake_minimum_required(VERSION 3.14)

project(snake)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${HHUOS_SRC_DIR}/application/snake/snake.cpp
        ${HHUOS_SRC_DIR}/application/snake/SnakeGame.cpp
        ${HHUOS_SRC_DIR}/application/snake/entity/SnakeEntity.cpp
        ${HHUOS_SRC_DIR}/application/snake/entity/FoodEntity.cpp
        ${HHUOS_SRC_DIR}/application/snake/text/SnakeScoreText.cpp
        ${HHUOS_SRC_DIR}/application/snake/scene/SnakeScene.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} lib.crt0 lib.user)