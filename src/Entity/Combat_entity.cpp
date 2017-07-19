#include <iostream>
#include "Character_creation/Character_creation_command.h"
#include "Entity/Combat_entity.h"
#include "Support/support.h"

Combat_entity::Combat_entity(const std::string& name, Gender gender, Race race, Job job) 
        : Ingame_entity_human(name, gender, race, job, false), m_innate_character_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1)
{
     character_creator();
}

Combat_entity::Combat_entity(const Combat_entity& old) 
{
    // copy constructor
}

void Combat_entity::character_creator()
{
    // sets name, gender, race, and character class
    // ingame_entity.h
    //set_information(); 
    // sets primary stats- primary attributes and secondary attributes
    // character_setup.h
    Factory_player_characters f_creator;
	f_creator.primary_stats_setup(job(), m_innate_character_stats);
}

void Combat_entity::reduce_or_increase_reputation(bool increase, int amount)
{
    if(increase == false)
    {
        m_innate_character_stats.reduce_reputation(amount);
    }
    else if(increase)
    {
        m_innate_character_stats.increase_reputation(amount);
    }
}

void Combat_entity::print_header_stats()
{
    std::cout << "Name: " << name() << " Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.experience_points() << "/" 
            << m_innate_character_stats.experience_points_needed() << std::endl;
}

void Combat_entity::print_stats()
{
    std::cout << "Name: " << name() << std::endl;
    std::cout << "Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.experience_points() << "/" << 
        m_innate_character_stats.experience_points_needed() << std::endl;
    std::cout << "Strength: " << m_innate_character_stats.strength() << std::endl;
    std::cout << "Leadership: " << m_innate_character_stats.leadership() << std::endl;
    std::cout << "Intelligence: " << m_innate_character_stats.intelligence() << std::endl;
    std::cout << "Character: " << m_innate_character_stats.character() << std::endl;
    std::cout << "Endurance: " << m_innate_character_stats.endurance() << std::endl;
    std::cout << "Speed: " << m_innate_character_stats.speed() << std::endl;
}

int Combat_entity::select_target(const std::vector<std::shared_ptr<Combat_entity>>& possible_targets)
{
    int selection = 0, i = 0, j = 0, stored_index[possible_targets.size()];
    
    std::cout << "What is your target?\n";
    for(auto it = possible_targets.begin(); it != possible_targets.end(); it++)
    {
        if(this->is_hostile() == false && (*it)->is_hostile())
        {
            ++i;
            std::cout << i << ". ";
            (*it)->print_header_stats();
            std::cout << std::endl;
            stored_index[j] = i;
        }
        ++j;
    }
    std::cout << "Input:";
    selection = get_number_from_user(1, i);
    return stored_index[selection];
}

bool Combat_entity::damage_entity(int amount_of_damage)
{
    bool f_success = true;
    
    // function in primary_stats that controls taking damage for the hostile
    f_success = m_innate_character_stats.take_damage(amount_of_damage);
    if(f_success)
    {
        std::cout << name() << " takes " << amount_of_damage << " hp of damage!" << std::endl;
    }
    else
    {
        std::cout << "Missed " << name() << "!" << std::endl;
    }
    return f_success;
}