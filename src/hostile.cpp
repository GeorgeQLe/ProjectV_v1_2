/*	Copyright 2016 George Le
    Definition of functions declared in hostile.h
*/
#include <iostream>
#include "hostile.h"
#include "entity_states.h"

Hostile::Hostile(std::string name, int gender, int race, int job, int strength, int leadership, int intelligence, int character,
            int endurance, unsigned int level, unsigned int total_health, int current_health_total, unsigned int defense,
            unsigned int speed)
            : Ingame_entity_human(name, gender, race, job, true), m_hostile_stats(strength, leadership, intelligence, character,
                                                                                endurance, level, total_health, current_health_total,
                                                                                defense, speed)
{
    get_AI();
}

void Hostile::print_header_stats()
{
    std::cout << "Name:" << name() << " Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
}

bool Hostile::turn(std::vector<Ingame_entity_human*>& turn_order)
{
    return update();
}

bool Hostile::update()
{
    bool f_success = true;
    
    mp_AI_system->update();
    
    return f_success;
}

void Hostile::attack()
{
    // TO BE IMPLEMENTED
}

void Hostile::move()
{
    // TO BE IMPLEMENTED
}

void Hostile::flee()
{
    std::cout << name() << " tries to flee";
    
}

void add_hostile(std::vector<Hostile*>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int)
{
    for(int i = 0; i < number_of_hostiles; i++)
    {
        // generates random hostile and inserts it into the list of hostiles
        Hostile* fp_hostile = new Hostile();
        list_of_hostiles.push_back(fp_hostile);
    }
}

bool Hostile::damage_entity(int amount_of_damage)
{
    bool f_success = true;
    
    // function in primary_stats that controls taking damage for the hostile
    f_success = m_hostile_stats.take_damage(amount_of_damage);
    std::cout << name() << " takes " << amount_of_damage << " hp of damage!" << std::endl;
    
    return f_success;
}