cmake_minimum_required(VERSION 3.7)

project(Battleships)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(PATH ./src)

set(SOURCE_FILES
        ${PATH}/ship.h
        ${PATH}/board.h
        )

set(EXE_NAME main)

add_executable(${EXE_NAME} ${PATH}/main.cpp ${SOURCE_FILES})
target_link_libraries(${EXE_NAME} ${SDL2_LIBRARIES})

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
                   COMMAND ${EXE_NAME}
                   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                   COMMENT "Running ${EXE_NAME}")