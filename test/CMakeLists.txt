cmake_minimum_required(VERSION 3.27.0)

project(Test VERSION 1.0.0 LANGUAGES CXX)

enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
target_link_libraries(${PROJECT_NAME} PRIVATE mem_lib misc_lib search_lib)


include(CTest)
add_test(NAME Sample-Test COMMAND ${PROJECT_NAME} [sample_test])
add_test(NAME Recursive-Fib-Test COMMAND ${PROJECT_NAME} [recursive_fibonacci])
add_test(NAME Dynamic-Fib-Test COMMAND ${PROJECT_NAME} [dynamic_fibonacci])