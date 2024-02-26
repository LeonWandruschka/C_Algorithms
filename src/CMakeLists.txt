cmake_minimum_required(VERSION 3.27.0)

project(Source VERSION 1.0.0 LANGUAGES C)

add_executable(Executable main.c)

target_link_libraries(Executable PRIVATE mem_lib misc_lib search_lib)

add_custom_target(runExecutable
    COMMAND ./src/Executable
    DEPENDS Executable
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running the executable as a post-build step"
)