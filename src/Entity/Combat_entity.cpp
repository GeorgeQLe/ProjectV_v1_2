#include <iostream>
#include "Character_creation/Character_creation_command.h"
#include "Entity/Combat_entity.h"
#include "Support/support.h"

// default constructor
CCombatEntity::CCombatEntity() : 
        CIngameEntityHuman("Dummy", 1, 1, 1, false), 
        m_innate_character_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) 
{
    // Empty constructor except for the initializer list
}

CCombatEntity::CCombatEntity(const std::string& name, Gender gender, Race race, Job job) :
        CIngameEntityHuman(name, gender, race, job, false), 
        m_innate_character_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1)
{
    // Calls character creation for primary_characters
     CharacterCreator();
}

CCombatEntity::CCombatEntity(const CCombatEntity& old) 
{
    // copy constructor if need TO BE Implemented
}

// simple constructor for hostile characters
CCombatEntity::CCombatEntity(const std::string& name, Gender gender, Race race, Job job, int difficulty) : 
        CIngameEntityHuman(name, gender, race, job, true),
    	m_innate_character_stats(difficulty, 1, 10, 10, 0, 1)
{
    // Empty constructor except for the initializer list
}

// constructor for specifically designed combat entites
CCombatEntity::CCombatEntity(const std::string& name, int gender, int race, int job, bool hostile, int strength, int leadership, 
        int intelligence, int character, int endurance, unsigned int level, unsigned int total_health, 
        int current_health_total, unsigned int defense, unsigned int speed) : 
        CIngameEntityHuman(name, gender, race, job, hostile),
        m_innate_character_stats(strength, leadership, intelligence, character, endurance, 
                                level, total_health, current_health_total, defense, speed) 
{
    // Empty constructor except for the initializer list
}

CCombatEntity::~CCombatEntity()
{
    // Empty destructor
}

void CCombatEntity::CharacterCreator()
{
    // sets name, gender, race, and character class
    // ingame_entity.h
    //set_information(); 
    // sets primary stats- primary attributes and secondary attributes
    // character_setup.h
    CFactoryPlayerCharacters f_creator;
	f_creator.PrimaryStatsSetup(GetJob(), m_innate_character_stats);
}

void CCombatEntity::ReduceOrIncreaseReputation(bool increase, int amount)
{
    if(increase == false)
    {
        m_innate_character_stats.ReduceReputation(amount);
    }
    else if(increase)
    {
        m_innate_character_stats.IncreaseReputation(amount);
    }
}

void CCombatEntity::PrintHeaderStats()
{
    std::cout << "Name: " << Name() << " Level: " << Level() << std::endl;
    std::cout << "Health: " << CurrentHealthTotal() << "/" << TotalHealth() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.ExperiencePoints() << "/" 
            << m_innate_character_stats.ExperiencePointsNeeded() << std::endl;
}

void CCombatEntity::PrintStats()
{
    std::cout << "Name: " << Name() << std::endl;
    std::cout << "Level: " << Level() << std::endl;
    std::cout << "Health: " << CurrentHealthTotal() << "/" << TotalHealth() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.ExperiencePoints() << "/" << 
        m_innate_character_stats.ExperiencePointsNeeded() << std::endl;
    std::cout << "Strength: " << m_innate_character_stats.Strength() << std::endl;
    std::cout << "Leadership: " << m_innate_character_stats.Leadership() << std::endl;
    std::cout << "Intelligence: " << m_innate_character_stats.Intelligence() << std::endl;
    std::cout << "Character: " << m_innate_character_stats.Character() << std::endl;
    std::cout << "Endurance: " << m_innate_character_stats.Endurance() << std::endl;
    std::cout << "Speed: " << m_innate_character_stats.Speed() << std::endl;
}

int CCombatEntity::SelectTarget(const std::vector<std::shared_ptr<CCombatEntity>>& possible_targets)
{
    int f_selection = 0, i = 0, j = 0, f_stored_index[possible_targets.size()];
    
    std::cout << "What is your target?\n";
    for(auto it = possible_targets.begin(); it != possible_targets.end(); it++)
    {
        if(this->IsHostile() == false && (*it)->IsHostile())
        {
            ++i;
            std::cout << i << ". ";
            (*it)->PrintHeaderStats();
            std::cout << std::endl;
            f_stored_index[j] = i;
        }
        ++j;
    }
    std::cout << "Input:";
    f_selection = get_number_from_user(1, i);
    return f_stored_index[f_selection];
}

bool CCombatEntity::DamageEntity(int amount_of_damage)
{
    bool f_success = true;
    
    // function in primary_stats that controls taking damage for the hostile
    f_success = m_innate_character_stats.TakeDamage(amount_of_damage);
    if(f_success)
    {
        std::cout << Name() << " takes " << amount_of_damage << " hp of damage!" << std::endl;
    }
    else
    {
        std::cout << "Missed " << Name() << "!" << std::endl;
    }
    
    return f_success;
}