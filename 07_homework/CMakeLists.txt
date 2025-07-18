cmake_minimum_required(VERSION 3.5)

project(07_homework)
add_subdirectory(googletest)

add_executable(containers_tests array_tests.cpp flist_tests.cpp)
target_link_libraries(containers_tests gtest_main gmock_main)

set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

