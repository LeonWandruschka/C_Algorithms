cmake_minimum_required(VERSION 3.27.0)

project(Search VERSION 1.0.0 LANGUAGES C)

# Set all files needed to build
set(SEARCH_FILES src/patternSearch.c)

add_library(${PROJECT_NAME} ${SEARCH_FILES})
add_library(search_lib ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)