cmake_minimum_required(VERSION 3.27.0)

project(Memory VERSION 1.0.0 LANGUAGES C)

# Set all files needed to build
set(MEMORY_FILES src/doublyLinkedList.c src/queue.c src/stack.c)

add_library(${PROJECT_NAME} ${MEMORY_FILES})
add_library(mem_lib ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC include)