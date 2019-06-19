cmake_minimum_required(VERSION 3.14)
project(toolbox)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES_TESTS
        unit_tests/tests_main.cpp
        unit_tests/memory_tests.cpp
        unit_tests/string_tests.cpp unit_tests/container_tests.cpp)

set(SOURCES_LIB
        src/toolbox/memory/chopping.hpp
        src/toolbox/memory/endianness.hpp
        src/toolbox/string/remove.hpp
        src/toolbox/containers/remove.hpp src/toolbox/string/query.hpp src/toolbox/containers/query.hpp src/toolbox/string/transform.hpp)

add_executable(toolbox ${SOURCES_LIB} ${SOURCES_TESTS})

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wduplicated-cond -Wformat=2 -Weffc++ -Wdouble-promotion -Wuseless-cast -Wnull-dereference -Wlogical-op -Wduplicated-branches  -Wmisleading-indentation -Wsign-conversion -Wpedantic -Wconversion -Woverloaded-virtual -Wunused -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align")
