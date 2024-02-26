cmake_minimum_required(VERSION 3.27.0)

project(Algorithms VERSION 1.0.0 LANGUAGES C)

option(CONAN "Enable Unit testing" OFF)

add_subdirectory(memory)
add_subdirectory(misc)
add_subdirectory(search)
add_subdirectory(src)

if(UNIT_TEST)
find_package(CATCH2 REQUIRED CONFIG)
include_directories(${CATCH2_INCLUDE_DIRS})

add_subdirectory(test)
endif()
