/*  Copyright 2017 George Le
    Defines the functions declared in character_setup.h  
*/
#include <iostream>
#include "Character_creation/Player_class_catalog.h"
#include "Character_creation/Character_creation_command.h"
#include "Support/support.h"

Custom_or_premade get_custom_or_premade()
{
    Custom_or_premade user_choice = NOTCREATED;
    bool confirm = false;
    do
    {
        confirm = false;
        std::cout << "Would you like to customize your stats or use the preset class stats?\n";
        std::cout << "1. Custom\n2. Preset\nInput (1-2): ";
        
        // function get_number_from_user is declared in support.h
        int choice = get_number_from_user(1, 2);
        
        if(choice == 1)
        {
            std::cout << "You elected to create a custom class.\n";
            std::cout << "Are you sure? (y/n): ";
            confirm = get_y_or_n_as_bool();
            if(confirm == true)
            {
                user_choice = CUSTOM;
            }
        }
        else if(choice == 2)
        {
            std::cout << "You elected to use the premade class.\n";
            std::cout << "Are you sure? (y/n): ";
            confirm = get_y_or_n_as_bool();
            if(confirm == true)
            {
                user_choice = PREMADE;
            }
        }   
    } while(!confirm);   
    // should not return NOTCREATED as get_number_from_user should only return 1 or 2
    return user_choice;
}

void Factory_player_characters::primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup)
{
    // m_user_choice is a member variable of the Factory_player_characters class
    // it is an enumerated type
    m_user_choice = get_custom_or_premade();
    if(m_user_choice == PREMADE)
    {
        // factory class designed to initialize the player's primary stats
        // found in character_class_information.h
        Player_class_catalog premade_class_information(player_class);
        // stats_to_be_setup is a Primary_stats class
        stats_to_be_setup.init_primary_stats(premade_class_information.get_strength(), premade_class_information.get_leadership(),
                                                        premade_class_information.get_intelligence(), premade_class_information.get_character(),
                                                        premade_class_information.get_endurance());
    }
    else if(m_user_choice == CUSTOM)
    {
        // TO BE DESIGNED
    }
}

void Factory_player_characters::secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats)
{
    // m_user_choice is a member variable of the Factory_player_characters class
    // it is an enumerated type
    if(m_user_choice == PREMADE)
    {
        // factory_secondary_stats is a Secondary_stats_initializer class
        learned_character_stats = factory_secondary_stats.init_secondary_stats_non_custom(static_cast<int>(player_class));
    }
    else if(m_user_choice == CUSTOM)
    {
        // TO BE DESIGNED
        //learned_character_stats = factory_secondary_stats.init_secondary_stats_custom(static_cast<int>(player_class));
    }
}