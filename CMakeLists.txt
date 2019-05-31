cmake_minimum_required(VERSION 3.13)
project(c3d2cl)
#include(ExternalPROJECT)
#ExternalProject_Add(project_ezc3d
#        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external
#        BINARY_DIR build/ezc3d
#        SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/ezc3d
#        CONFIGURE_COMMAND "-DBUILD_SHARED_LIBS=False"
#        INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/lib"
#        )
add_subdirectory(external/ezc3d)
set(CMAKE_CXX_STANDARD 14)
#ExternalProject_Get_Property(project_ezc3d install_dir)
#add_library(ezc3d STATIC IMPORTED)
add_executable(c3d2cl main.cpp)
target_link_libraries(c3d2cl ezc3d)