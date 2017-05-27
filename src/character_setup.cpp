/*  Copyright 2017 George Le
    
*/
#include <iostream>
#include "character_class_information.h"
#include "character_setup.h"
#include "support.h"

void Character_set_up_player_characters::primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup)
{
    m_user_choice = get_custom_or_premade();
    if(m_user_choice == PREMADE)
    {
        Player_class_catalog premade_class_information(player_class);
        stats_to_be_setup.init_primary_stats(premade_class_information.get_strength(), premade_class_information.get_leadership(),
                                                        premade_class_information.get_intelligence(), premade_class_information.get_character(),
                                                        premade_class_information.get_endurance());
    }
    else if(m_user_choice == CUSTOM)
    {
        //TO DESIGN
    }
}

void Character_set_up_player_characters::secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats)
{
    if(m_user_choice == PREMADE)
    {
        factory_secondary_stats.init_secondary_stats_non_custom(learned_character_stats, static_cast<int>(player_class));
    }
    else if(m_user_choice == CUSTOM)
    {
        factory_secondary_stats.init_secondary_stats_custom(learned_character_stats, static_cast<int>(player_class));
    }
}

Custom_or_premade get_custom_or_premade()
{
    std::cout << "Would you like to customize your stats or use the preset class stats?\n";
    std::cout << "1. Custom\n2. Preset\nInput (1-2): ";
    
    int choice = get_number_from_user(1, 2);
    
    if(choice == 1)
    {
        std::cout << "You elected to create a custom class.\n";
        std::cout << "Are you sure? (y/n): ";
        
        if(get_y_or_n_as_bool() == false)
        {
            get_custom_or_premade();
        }
        else
        {
            return CUSTOM;    
        }
    }
    else if(choice == 2)
    {
        std::cout << "You elected to use the premade class.\n";
        std::cout << "Are you sure? (y/n): ";
        
        if(get_y_or_n_as_bool() == false)
        {
            get_custom_or_premade();
        }
        else
        {
            return PREMADE;
        }
    }
    
    return NOTCREATED;
}