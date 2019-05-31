cmake_minimum_required(VERSION 3.13)
project(c3d2cl)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(external/ezc3d)
add_executable(c3d2cl src/main.cpp)
target_link_libraries(c3d2cl ezc3d)