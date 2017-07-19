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
    src/Actions/Actions.cpp
    src/Actions/Flee_action.cpp
    src/Actions/Movement_action.cpp
    src/Character_creation/Character_creation_command.cpp
    src/Character_creation/Player_class_catalog.cpp
    src/Combat_manager/Combat_manager.cpp
    src/Diadal/Diadal.cpp
    src/Diadal/Diadal_story.cpp
    src/Diadal/ProjectV_driver.cpp
    src/Entity/Combat_entity.cpp
    src/Entity/Hostile.cpp
    src/Entity/Ingame_entity.cpp
    src/Entity/Primary_character.cpp
    src/Game/Game.cpp
    src/List_of_attacks.cpp
    src/Primary_stats/Primary_stats.cpp
    src/Secondary_stats/Secondary_stats.cpp
    src/Secondary_stats/Secondary_stats_creator.cpp
    src/Support/random.cpp
    src/Support/support.cpp
)

set(DIADAL_HEADERS
    include/Actions/Actions.h
    include/Actions/Flee_action.h
    include/Actions/Movement_action.h
    include/AI/Base_state.h
    include/AI/Entity_states.h
    include/AI/Entity_states.imp
    include/AI/State_machine.h
    include/AI/State_machine.imp
    include/Character_creation/Character_creation_command.h
    include/Character_creation/Player_class_catalog.h
    include/Combat_manager/Combat_manager.h
    include/Diadal/Diadal.h
    include/Diadal/Diadal_story.h
    include/Entity/Combat_entity.h
    include/Entity/Hostile.h
    include/Entity/Ingame_entity.h
    include/Entity/Primary_character.h
    include/Game/Game.h
    include/Grid/Grid.h
    include/Grid/Grid.imp
    include/Grid/Grid_square.h
    include/List_of_attacks.h
    include/Primary_stats/Primary_stats.h
    include/Secondary_stats/Secondary_stats.h
    include/Secondary_stats/Secondary_stats_creator.h
    include/Support/random.h
    include/Support/random_messages.h
    include/Support/support.h
    include/Support/vector_quicksort.h
    include/Support/vector_quicksort.imp
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