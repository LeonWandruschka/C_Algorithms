cmake_minimum_required(VERSION 3.27.0)

project(Source VERSION 1.0.0 LANGUAGES CXX)

add_executable(test_exec main.cpp)

target_link_libraries(test_exec PRIVATE mem_lib misc_lib search_lib)
target_link_libraries(test_exec PRIVATE Catch2::Catch2WithMain)

add_custom_target(runTest
    COMMAND ./test/test_exec
    DEPENDS test_exec
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running the Test as a post-build step"
)