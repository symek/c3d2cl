cmake_minimum_required(VERSION 3.6.1)
project(c3d2cl)

set(CMAKE_CXX_STANDARD 14)

list( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")
list( APPEND CMAKE_PREFIX_PATH "$ENV{HT}/cmake")

find_package( Houdini REQUIRED )

message (STATUS "Houdini HDK: ${Houdini_VERSION}")

# Can't use add_subdirectory since forfor some reason after linking
# with Houdini I loose ezc3d linkage
#add_subdirectory(external/ezc3d)
# ...so I had to add sources files directly
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/external/ezc3d/src/*.cpp)

add_executable(c3d2cl src/c3d2cl.cpp
                      ${SRC_FILES})

target_link_libraries(c3d2cl Houdini)

target_include_directories(c3d2cl PUBLIC external/ezc3d/include)

