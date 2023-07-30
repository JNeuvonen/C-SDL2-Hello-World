cmake_minimum_required(VERSION 3.10)
project(minigolf.bin)

set(CMAKE_C_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.c")
add_executable(minigolf.bin ${SOURCES})

set(SDL2_LIBRARIES "/Library/Frameworks/SDL2.framework")
set(SDL2_IMAGE "/Library/Frameworks/SDL2_image.framework")

target_link_libraries(minigolf.bin ${SDL2_LIBRARIES} SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf)
