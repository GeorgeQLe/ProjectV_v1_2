/*  Copyright 2017 George Le
    Definitions of member functions of the Secondary_stats_creator class
*/
#include "Secondary_stats/Secondary_stats_creator.h"

Secondary_stats_creator::Secondary_stats_creator(const std::string& script_name) : custom_creation_script(script_name) 
{
    
}  

Secondary_stats Secondary_stats_creator::init_secondary_stats_non_custom(int player_class_converted_from_enum)
{
    Secondary_stats temp;
    // find out which player class the player is
    switch(player_class_converted_from_enum)
    {
        // marine
        case 1:
        // stats_to_be_init.medicine_knowledge+=2;
        // stats_to_be_init.athletics+=2;
        // stats_to_be_init.intimidation+=2;
        break;
        // naval captain
        case 2:
        // stats_to_be_init.wisdom+=2;
        // stats_to_be_init.dexterity+=2;
        // stats_to_be_init.persuasion+=2;
        break;
        // lawyer
        case 3:
        break;
        // armorer
        case 4:
        break;
        // economist
        case 5:
        break;
        default:
        break;
    }
    return temp;
}

void Secondary_stats_creator::init_secondary_stats_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum)
{
    //woah some complex shit to be designed
}

void Secondary_stats_creator::scenes_Marine_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_creator::scenes_Naval_captain_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_creator::scenes_Lawyer_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_creator::scenes_Armorer_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_creator::scenes_Economist_custom(Secondary_stats& stats_to_be_init)
{
    
}