cmake_minimum_required(VERSION 3.13)
project(c3d2cl)

set(CMAKE_CXX_STANDARD 14)

list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
list( APPEND CMAKE_PREFIX_PATH "$ENV{HT}/cmake")

find_package( Houdini REQUIRED )

message (STATUS "Houdini HDK: ${Houdini_VERSION}")

add_executable(c3d2cl src/c3d2cl.cpp)

add_subdirectory(external/ezc3d)

#target_link_libraries(c3d2cl )
target_link_libraries(c3d2cl Houdini ezc3d)

