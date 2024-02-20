cmake_minimum_required(VERSION 3.27.0)

project(Misc VERSION 1.0.0 LANGUAGES C)

# Set all files needed to build
set(MISC_FILES src/dynamicFib.c src/recursiveFib.c)

add_library(${PROJECT_NAME} ${MISC_FILES})
add_library(misc_lib ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)
