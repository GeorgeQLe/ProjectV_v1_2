project(tests)

cmake_minimum_required(VERSION 2.8)
cmake_policy(VERSION 2.8)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb3 -O0")
elseif(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11 /MP /Wall")
endif()

set(TEST_SOURCES
    src/Driver.cpp
    src/Unit_test.cpp
)

set(TEST_HEADERS
    include/Grid.h
    include/Grid.imp
    include/Grid_square.h
    include/Grid_square.imp
)

include_directories(include)

add_executable(
    ${PROJECT_NAME}
    ${TEST_HEADERS}
    ${TEST_SOURCES}
)