cmake_minimum_required(VERSION 3.5)
project(tddWs)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${GMOCK_INCLUDE_DIRS}
)

add_executable(tddWs main.cpp GameInterfaces.hpp)
set_property(TARGET tddWs PROPERTY CXX_STANDARD 14)


add_executable(tests sampleTests.cpp)
target_link_libraries(tests
        gtest
        gmock
        gtest_main)

set_property(TARGET tddWs PROPERTY CXX_STANDARD 14)

#this is a bit of overkill, but it enables to run ctest
enable_testing()

add_test(
        NAME allTests
        COMMAND tests
)
