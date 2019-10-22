cmake_minimum_required(VERSION 3.5)
project(dojo)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

include(cmake/GTest.cmake)

include_directories(
        .
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)

add_executable(dojo
    #lcd.cpp
    #maze.cpp
    saddle.cpp
    )

target_link_libraries(dojo
        gmock_main
        gtest
        gmock
        Threads::Threads)

