project(projectV)

cmake_minimum_required(VERSION 2.8)
cmake_policy(VERSION 2.8)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s -O3")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3 -ggdb3 -O0")
elseif(WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11 /MP /Wall")
endif()

set(DIADAL_SOURCES
    src/actions.cpp
    src/attacks.cpp
    src/basic_state_AI.cpp
    src/character_class_information.cpp
    src/character_setup.cpp
    src/combat.cpp
    src/Diadal.cpp
    src/Diadal_story.cpp
    src/entity_manager.cpp
    src/entity_states.cpp
    src/game.cpp
    src/hostile.cpp
    src/ingame_entity.cpp
    src/primary_character.cpp
    src/primary_stats.cpp
    src/projectV_driver.cpp
    src/secondary_stats.cpp
    src/support.cpp
)

set(DIADAL_HEADERS
    include/actions.h
    include/attacks.h
    include/basic_state_AI.h
    include/character_class_information.h
    include/character_setup.h
    include/combat.h
    include/Diadal.h
    include/Diadal_story.h
    include/entity_manager.h
    include/entity_states
    include/game.h
    include/hostile.h
    include/ingame_entity.h
    include/primary_character.h
    include/primary_stats.h
    include/secondary_stats.h
    include/support.h
    include/vector_quicksort.h
    include/vector_quicksort.imp
)

include_directories(include)

add_executable(${PROJECT_NAME}
    ${DIADAL_HEADERS}
    ${DIADAL_SOURCES}
)

set(DIADAL_DATA
    data/Diadal_script_intro.txt
    data/Diadal_text_files.txt
    data/Diadal_script_character_creation.txt
    data/Diadal_script_prologue.txt
)

foreach(DATA ${DIADAL_DATA})
    configure_file(${DATA} ${CMAKE_CURRENT_BINARY_DIR}/${DATA_FILENAME} COPYONLY)
endforeach()