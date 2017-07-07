/*	Copyright 2016 George Le
    Definition of functions declared in hostile.h
*/
#include "hostile.h"

Hostile::Hostile(std::string name, int gender, int race, int job, int strength, int leadership, int intelligence, int character,
            int endurance, unsigned int level, unsigned int total_health, int current_health_total, unsigned int defense,
            unsigned int speed)
            : Ingame_entity_human(name, gender, race, job, true), m_hostile_stats(strength, leadership, intelligence, character,
                                                                                endurance, level, total_health, current_health_total,
                                                                                defense, speed)
{
    get_AI();
}

void Hostile::update()
{
    // TO BE IMPLEMENTED
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
    // TO BE IMPLEMENTED
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