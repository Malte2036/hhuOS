cmake_minimum_required(VERSION 3.14)

project(snake)
message(STATUS "Project " ${PROJECT_NAME})

include_directories(${HHUOS_SRC_DIR})

# Set source files
set(SOURCE_FILES
        ${HHUOS_SRC_DIR}/application/snake/snake.cpp
        ${HHUOS_SRC_DIR}/application/snake/SnakeGame.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES}
        ../../../src/application/snake/SnakeEntity.h ../../../src/application/snake/SnakeEntity.cpp
        ../../../src/application/snake/FoodEntity.h ../../../src/application/snake/FoodEntity.cpp)

target_link_libraries(${PROJECT_NAME} lib.crt0 lib.user)