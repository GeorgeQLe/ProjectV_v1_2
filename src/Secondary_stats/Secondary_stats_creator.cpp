/*  Copyright 2017 George Le
    Definitions of member functions of the CSecondaryStatsCreator class
*/
#include "Secondary_stats/Secondary_stats_creator.h"

CSecondaryStatsCreator::CSecondaryStatsCreator(const std::string& script_name) : custom_creation_script(script_name) 
{
    
}  

CSecondaryStats CSecondaryStatsCreator::InitSecondaryStatsNonCustom(int player_class_converted_from_enum)
{
    CSecondaryStats temp;
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

void CSecondaryStatsCreator::InitSecondaryStatsCustom(CSecondaryStats& stats_to_be_init, int player_class_converted_from_enum)
{
    //woah some complex shit to be designed
}

void CSecondaryStatsCreator::ScenesMarineCustom(CSecondaryStats& stats_to_be_init)
{
    
}

void CSecondaryStatsCreator::ScenesNavalCaptainCustom(CSecondaryStats& stats_to_be_init)
{
    
}

void CSecondaryStatsCreator::ScenesLawyerCustom(CSecondaryStats& stats_to_be_init)
{
    
}

void CSecondaryStatsCreator::ScenesArmorerCustom(CSecondaryStats& stats_to_be_init)
{
    
}

void CSecondaryStatsCreator::ScenesEconomistCustom(CSecondaryStats& stats_to_be_init)
{
    
}