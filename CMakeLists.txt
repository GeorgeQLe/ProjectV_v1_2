cmake_minimum_required(VERSION 3.0)
cmake_policy(VERSION 3.0)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb3 -O0")
elseif(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11 /MP /Wall")
endif()

set(DIADAL_SOURCES
    actions.cpp
    attacks.cpp
    character_class_information.cpp
    character_setup.cpp
    combat.cpp
    Diadal.cpp
    Diadal_story.cpp
    Diadal_story.cpp
    game.cpp
    hostile.cpp
    ingame_entity.cpp
    primary_character.cpp
    primary_stats.cpp
    projectV_driver.cpp
    scene.cpp
    secondary_stats.cpp
    support.cpp
)

set(DIADAL_HEADERS
    actions.h
    attacks.h
    character_class_information.h
    character_setup.h
    combat.h
    Diadal.h
    Diadal_story.h
    Diadal_story.h
    game.h
    hostile.h
    ingame_entity.h
    primary_character.h
    primary_stats.h
    scene.h
    secondary_stats.h
    support.h
)

add_executable(projectV
    ${DIADAL_HEADERS}
    ${DIADAL_SOURCES}
)
