/*  Copyright 2017 George Le
    Defines the functions declared in character_setup.h  
*/
#include <iostream>
#include "Character_creation/Player_class_catalog.h"
#include "Character_creation/Character_creation_command.h"
#include "Support/support.h"

Custom_or_premade GetCustomOrPremade()
{
    Custom_or_premade f_user_choice = NOTCREATED;
    bool f_confirm = false;
    do
    {
        f_confirm = false;
        std::cout << "Would you like to customize your stats or use the preset class stats?\n";
        std::cout << "1. Custom\n2. Preset\nInput (1-2): ";
        
        // function get_number_from_user is declared in support.h
        int f_choice = get_number_from_user(1, 2);
        
        if(f_choice == 1)
        {
            std::cout << "You elected to create a custom class.\n";
            std::cout << "Are you sure? (y/n): ";
            f_confirm = get_y_or_n_as_bool();
            if(f_confirm == true)
            {
                f_user_choice = CUSTOM;
            }
        }
        else if(f_choice == 2)
        {
            std::cout << "You elected to use the premade class.\n";
            std::cout << "Are you sure? (y/n): ";
            f_confirm = get_y_or_n_as_bool();
            if(f_confirm == true)
            {
                f_user_choice = PREMADE;
            }
        }   
    } while(!f_confirm);   
    // should not return NOTCREATED as get_number_from_user should only return 1 or 2
    return f_user_choice;
}

void CFactoryPlayerCharacters::PrimaryStatsSetup(Job player_class, CPrimaryStats& stats_to_be_setup)
{
    // m_user_choice is a member variable of the CFactoryPlayerCharacters class
    // it is an enumerated type
    m_user_choice = GetCustomOrPremade();
    if(m_user_choice == PREMADE)
    {
        // factory class designed to initialize the player's primary stats
        // found in character_class_information.h
        CPlayerClassCatalog premade_class_information(player_class);
        // stats_to_be_setup is a Primary_stats class
        stats_to_be_setup.InitPrimaryStats(premade_class_information.GetStrength(), premade_class_information.GetLeadership(),
                                        premade_class_information.GetIntelligence(), premade_class_information.GetCharacter(),
                                        premade_class_information.GetEndurance());
    }
    else if(m_user_choice == CUSTOM)
    {
        // TO BE DESIGNED
    }
}

void CFactoryPlayerCharacters::SecondaryStatsSetup(Job player_class, CSecondaryStats& learned_character_stats)
{
    // m_user_choice is a member variable of the CFactoryPlayerCharacters class
    // it is an enumerated type
    if(m_user_choice == PREMADE)
    {
        // factory_secondary_stats is a Secondary_stats_initializer class
        learned_character_stats = factory_secondary_stats.InitSecondaryStatsNonCustom(static_cast<int>(player_class));
    }
    else if(m_user_choice == CUSTOM)
    {
        // TO BE DESIGNED
        //learned_character_stats = factory_secondary_stats.init_secondary_stats_custom(static_cast<int>(player_class));
    }
}