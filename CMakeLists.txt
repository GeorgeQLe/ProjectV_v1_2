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
    src/Actions.cpp
    src/Character_class_information.cpp
    src/character_setup.cpp
    src/Combat_entity.cpp
    src/Combat_manager.cpp
    src/Diadal.cpp
    src/Diadal_story.cpp
    src/Flee_action.cpp
    src/Game.cpp
    src/Hostile.cpp
    src/Ingame_entity.cpp
    src/List_of_attacks.cpp
    src/Movement_action.cpp
    src/Primary_character.cpp
    src/Primary_stats.cpp
    src/ProjectV_driver.cpp
    src/random.cpp
    src/Secondary_stats.cpp
    src/support.cpp
)

set(DIADAL_HEADERS
    include/Actions.h
    include/Base_state.h
    include/Character_class_information.h
    include/character_setup.h
    include/Combat_entity.h
    include/Combat_manager.h
    include/Diadal.h
    include/Diadal_story.h
    include/Entity_states.h
    include/Entity_states.imp
    include/Flee_action.h
    include/Game.h
    include/Grid.h
    include/Hostile.h
    include/Ingame_entity.h
    include/List_of_attacks.h
    include/Movement_action.h
    include/Primary_character.h
    include/Primary_stats.h
    include/random.h
    include/random_messages.h
    include/Secondary_stats.h
    include/State_machine.h
    include/State_machine.imp
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