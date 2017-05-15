#include <iostream>
#include "secondary_stats.h"
#include "support.h"

void Secondary_stats_initializer::init_secondary_stats_non_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum)
{
    // find out which player class the player is
    switch(player_class_converted_from_enum)
    {
        // marine
        case 1:
        break;
    }
}

void Secondary_stats_initializer::init_secondary_stats_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum)
{
    //woah some complex shit to be designed
}

void Secondary_stats_initializer::on_Read(const std::string& Event_name)
{
    read_from_script(Event_name);
}

void Secondary_stats_initializer::scenes_Marine_custom(various_Secondary_stats& stats_to_be_init)
{
    on_Read("SCENE_ONE_MARINE_CUSTOM");
    get_number_from_user(1, 4);
}

void Secondary_stats_initializer::scenes_Naval_captain_custom(various_Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Lawyer_custom(various_Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Armorer_custom(various_Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Economist_custom(various_Secondary_stats& stats_to_be_init)
{
    
}