/*  Copyright 2016 George Le
    Declaration of CCharacterCreationCommand base class and its pure virtual functions
*/
#ifndef CHARACTER_SETUP_H
#define CHARACTER_SETUP_H

#include <string>

//including primary and secondary stat for function parameter in class 
//character set up's member function character creation
#include "Entity/Ingame_entity.h"
#include "Primary_stats/Primary_stats.h"
#include "Secondary_stats/Secondary_stats_creator.h"

enum Custom_or_premade { NOTCREATED, CUSTOM, PREMADE };

// function to get a choice from the user of whether or not to use the preset classes made
// or to directly control their starting stats
Custom_or_premade GetCustomOrPremade();

class CCharacterCreationCommand
{
    public:
    CCharacterCreationCommand() {}
    virtual void PrimaryStatsSetup(Job player_class, CPrimaryStats& stats_to_be_setup) = 0;
    virtual void SecondaryStatsSetup(Job player_class, CSecondaryStats& learned_character_stats) = 0;
};

class CFactoryPlayerCharacters : public CCharacterCreationCommand
{
    public:
    CFactoryPlayerCharacters() : script_name("Diadal_script_character_creation.txt"), factory_secondary_stats(script_name), 
                                            m_user_choice(NOTCREATED) 
    { 
        while(m_user_choice)
        {
            m_user_choice = GetCustomOrPremade(); 
        }
    }
    
    void PrimaryStatsSetup(Job player_class, CPrimaryStats& stats_to_be_setup);
    void SecondaryStatsSetup(Job player_class, CSecondaryStats& learned_character_stats);
    
    private:
    const std::string script_name;
    CSecondaryStatsCreator factory_secondary_stats;
    
    Custom_or_premade m_user_choice;
};

class CCharacterSetupHostileCharacters : public CCharacterCreationCommand
{
    // does something different than for player characters   
    // probably not will be used
};

class CCharacterSetupNPC : public CCharacterCreationCommand
{
    // sets up character for npcs  
};

#endif