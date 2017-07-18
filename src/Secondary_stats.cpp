#include <iostream>
#include "Secondary_stats.h"
#include "support.h"

bool Secondary_stats::check_stat(unsigned int& your_stat, unsigned int difficulty_check)
{
    if(your_stat >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++your_stat;
        return true;
    }
    // else return failure
    return false;
}

void Secondary_stats_initializer::init_secondary_stats_non_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum)
{
    // find out which player class the player is
    switch(player_class_converted_from_enum)
    {
        // marine
        case 1:
        stats_to_be_init.medical_knowledge+=2;
        stats_to_be_init.athletics+=2;
        stats_to_be_init.intimidation+=2;
        break;
        // naval captain
        case 2:
        stats_to_be_init.wisdom+=2;
        stats_to_be_init.dexterity+=2;
        stats_to_be_init.persuasion+=2;
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
}

void Secondary_stats_initializer::init_secondary_stats_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum)
{
    //woah some complex shit to be designed
}

void Secondary_stats_initializer::scenes_Marine_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Naval_captain_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Lawyer_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Armorer_custom(Secondary_stats& stats_to_be_init)
{
    
}

void Secondary_stats_initializer::scenes_Economist_custom(Secondary_stats& stats_to_be_init)
{
    
}