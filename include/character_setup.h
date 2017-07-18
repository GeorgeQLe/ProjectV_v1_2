/*  Copyright 2016 George Le
    
*/
#ifndef CHARACTER_SETUP_H
#define CHARACTER_SETUP_H

#include <string>

//including primary and secondary stat for function parameter in class 
//character set up's member function character creation
#include "Ingame_entity.h"
#include "Primary_stats.h"
#include "Secondary_stats.h"

enum Custom_or_premade { NOTCREATED, CUSTOM, PREMADE };

// function to get a choice from the user of whether or not to use the preset classes made
// or to directly control their starting stats
Custom_or_premade get_custom_or_premade();

class Character_set_up_command
{
    public:
    Character_set_up_command() {}
    virtual void primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup) = 0;
    virtual void secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats) = 0;
};

class Factory_player_characters : public Character_set_up_command
{
    public:
    Factory_player_characters() : script_name("Diadal_script_character_creation.txt"), factory_secondary_stats(script_name), 
                                            m_user_choice(NOTCREATED) 
    { 
        while(m_user_choice)
        {
            m_user_choice = get_custom_or_premade(); 
        }
    }
    
    void primary_stats_setup(Job player_class, Primary_stats& stats_to_be_setup);
    void secondary_stats_setup(Job player_class, Secondary_stats& learned_character_stats);
    
    private:
    const std::string script_name;
    Secondary_stats_initializer factory_secondary_stats;
    
    Custom_or_premade m_user_choice;
};

class Character_set_up_hostile_characters : public Character_set_up_command
{
    // does something different than for player characters   
    // probably not will be used
};

class Character_set_up_npc : public Character_set_up_command
{
    // sets up character for npcs  
};

#endif