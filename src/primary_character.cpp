/*  Copyright 2017 George Le
    Definitions of functions declared in primary_character.h
*/
#include <iostream>
#include "primary_character.h"
#include "character_setup.h"

Primary_character::Primary_character() 
                : Ingame_entity_human{"Adam", MALE, WHITE, CAPTAIN}, m_character_ethics(LAWFUL_NEUTRAL), m_player_character(false)
{
    character_creator();
}

void Primary_character::character_creator()
{
    //sets name, gender, race, and character class
    //ingame_entity.h
    set_information(); 
    //sets primary stats- primary attributes and secondary attributes
    //character_setup.h
    Factory_player_characters f_creator;
	f_creator.primary_stats_setup(get_job(), m_innate_character_stats);
	f_creator.secondary_stats_setup(get_job(), m_learned_character_stats);
}

void Primary_character::party_character_creator()
{
    // TO BE DESIGNED
}

void Primary_character::reduce_or_increase_reputation(const Reputation_change& reduce_or_increase, int amount)
{
    if(reduce_or_increase == REDUCE)
    {
        m_innate_character_stats.reduce_reputation(amount);
    }
    else if(reduce_or_increase == INCREASE)
    {
        m_innate_character_stats.increase_reputation(amount);
    }
}

void Primary_character::attack()
{
    // TO BE IMPLEMENTED
}