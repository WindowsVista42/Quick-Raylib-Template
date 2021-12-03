cmake_minimum_required(VERSION 3.10)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -mavx2")

file(GLOB SRC src/*.cpp)
add_executable(run ${SRC})

find_package(raylib REQUIRED)

target_link_libraries(run raylib)
