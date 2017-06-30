/*  Copyright 2017 George Le
    Definitions of functions declared in primary_character.h
*/
#include <iostream>
#include "primary_character.h"
#include "character_setup.h"

Primary_character::Primary_character(bool f_player) 
                : Ingame_entity_human{"Adam", MALE, WHITE, CAPTAIN}, m_character_ethics(LAWFUL_NEUTRAL), m_player_character(false)
{
    // checks if the primary_character to be created is the player
    if(f_player)
    {
        // if so call the special player character creation
        character_creator();
    }
    else
    {
        // called to create the player's party characters
        party_character_creator();
    }
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

void Primary_character::reduce_or_increase_reputation(Change_stat f_reduce_or_increase, int f_amount)
{
    if(f_reduce_or_increase == REDUCE)
    {
        m_innate_character_stats.reduce_reputation(f_amount);
    }
    else if(f_reduce_or_increase == INCREASE)
    {
        m_innate_character_stats.increase_reputation(f_amount);
    }
}

unsigned int Primary_character::level() const
{
    return m_innate_character_stats.level();
}

unsigned int Primary_character::total_health() const
{
    return m_innate_character_stats.total_health();
}

unsigned int Primary_character::current_health_total() const
{
    return m_innate_character_stats.current_health_total();
}

unsigned int Primary_character::speed() const
{
    return m_innate_character_stats.speed();
}

void Primary_character::attack()
{
    // TO BE IMPLEMENTED
}