cmake_minimum_required(VERSION 3.5)
project(dojo)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)


include_directories(
        .
        googletest/googletest
        googletest/goooglemock
)

add_executable(
        run_tests
        maze.cpp)

target_link_libraries(
        run_tests
        gtest
        gmock
        Threads::Threads)

