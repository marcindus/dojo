cmake_minimum_required(VERSION 3.5)
project(dojo)

set(CMAKE_CXX_STANDARD 14)
#add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-Wall -Wextra )

include(cmake/GTest.cmake)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)

#add_executable(tddWs main.cpp GameInterfaces.hpp)
#set_property(TARGET tddWs PROPERTY CXX_STANDARD 14)


#add_executable(test_saddle saddle.cpp)
#add_executable(test_lcd lcd.cpp)
#add_executable(test_maze maze.cpp)
#add_executable(test_balanced isBalanced.cpp)
add_executable(test_rover rover.cpp)

target_link_libraries(test_rover
        gtest
        gmock
        gtest_main)

set_property(TARGET test_rover PROPERTY CXX_STANDARD 14)

#this is a bit of overkill, but it enables to run ctest
enable_testing()

add_test(
        NAME allTests
        COMMAND tests
)
