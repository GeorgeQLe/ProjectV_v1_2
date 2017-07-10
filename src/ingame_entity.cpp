/*  Copyright 2016 George Le
    Definition of functions declared in ingame_entity.h
*/
#include <iostream>
#include "ingame_entity.h"
#include "support.h"

unsigned int Ingame_entity_human::s_next_valid_ID = 0;

// special constructor for passing ints in the creation of an object
Ingame_entity_human::Ingame_entity_human(const std::string& name, int gender, int race, int job, bool is_hostile) 
                                        : m_is_hostile(is_hostile), m_entity_name(name)
{
    // MAX_GENDER value found in ingame_entity.h
    if(gender > 0 && gender <= MAX_GENDER)
    {
        // private member function of ingame_entity_human
	    set_gender(gender); 
    }
    
    // MAX_RACE value found in ingame_entity.h
	if(race > 0 && race <= MAX_RACE)
	{
	    // private member function of ingame_entity_human
	    set_race(race); 
	}
	
	// MAX_CLASSES value found in ingame_entity.h
	if(job > 0 && job<= MAX_CLASSES)
	{
	    // private member function of ingame_entity_human
	    set_job(job);
	}
	
	set_ID();
}

int Ingame_entity_human::select_target(const std::vector<Ingame_entity_human*>& possible_targets)
{
    int selection = 0, i = 1;
    
    std::cout << "What is your target?";
    for(auto it = possible_targets.begin(); it != possible_targets.end(); it++)
    {
        if(this->is_hostile() == false && (*it)->is_hostile())
        {
                std::cout << i << "." << (*it)->name() << std::endl;
                ++i;
        }
    }
    std::cout << "Input:";
    selection = get_number_from_user(1, i);
    return selection;
}

std::string Ingame_entity_human::get_gender_as_string() const
{
    // m_entity_gender is a member variable of the Ingame_entity_human class found in ingame_entity.h
    switch(m_entity_gender)
    {
        case 1:
        return "male";
        break;
        case 2:
        return "female";
        break;
        case 3:
        return "other";
        break;
        default:
        break;
    }
    return "UNINIT Programmer messed up... Wait that's me...";
}

std::string Ingame_entity_human::get_race_as_string() const
{
    // m_entity_race is a member variable of the Ingame_entity_human class found in ingame_entity.h
    switch(m_entity_race)
    {
        case 1:
        return "white";
        break;
        case 2:
        return "black";
        break;
        case 3:
        return "asian";
        break;
        case 4:
        return "hispanic";
        break;
        case 5:
        return "indigenous";
        break;
        case 6:
        return "other";
        break;
        default:
        break;
    }
    return "UNSET Programmer messed up... Wait that's me...";
}

std::string Ingame_entity_human::get_job_as_string() const
{
    // m_entity_class is a member variable of the Ingame_entity_human class found in ingame_entity.h
    switch(m_entity_class)
    {
        case 1:
        return "marine";
        break;
        case 2:
        return "captain";
        break;
        case 3:
        return "lawyer";
        break;
        case 4:
        return "armorer";
        break;
        case 5:
        return "economist";
        break;
        case 6:
        return "gambler";
        break;
        case 7:
        return "reporter";
        break;
        case 8:
        return "nomad";
        break;
        default:
        break;
    }
    return "UNEMPLOYED Programmer messed up... Wait that's me...";
}

// TO BE REDONE
void Ingame_entity_human::set_information()
{
    std::cout << "This is a temporary build\n";
    std::cout << "What would you like your ingame name to be?\nInput:";
    m_entity_name = getline_from_user_restricted(1, 10);
    std::cout << "What is your preferred gender?\n1.Male\n2.Female\n3.Other\nInput:";
    m_entity_gender = static_cast<Gender>(get_number_from_user(1,3));
    std::cout << "What is your race?\n1.White\n2.Black\n3.Asian or Pacific Islander\n4.Hispanic\n5.Indigenous People\n6.Other\nInput:";
    m_entity_race = static_cast<Race>(get_number_from_user(1, 6));
    std::cout << "What is your class?\n1.Marine\n2.Captain\n3.Lawyer\nInput:";
    m_entity_class = static_cast<Job>(get_number_from_user(1, 3));
}

void Ingame_entity_human::set_ID()
{
    m_ID = s_next_valid_ID;
    ++s_next_valid_ID;
}