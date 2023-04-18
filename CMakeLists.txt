cmake_minimum_required(VERSION 3.7)

project(Battleships)

INCLUDE(FindPkgConfig)
find_package(SDL2 REQUIRED)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

set(PATH ./src)

set(SOURCE_FILES
        ${PATH}/ship.h
        ${PATH}/ship.cpp
        ${PATH}/board.h
        ${PATH}/board.cpp
        ${PATH}/game.h
        ${PATH}/game.cpp
)

set(EXE_NAME main)

add_executable(${EXE_NAME} ${PATH}/main.cpp ${SOURCE_FILES})
target_include_directories(${EXE_NAME} PRIVATE include ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS})
target_link_libraries(${EXE_NAME} ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARIES})


add_custom_command(TARGET ${EXE_NAME} POST_BUILD
                   COMMAND ${EXE_NAME}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running ${EXE_NAME}")