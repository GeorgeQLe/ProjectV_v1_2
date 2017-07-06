/*  Copyright 2017 George Le
    Definitions of functions declared in primary_character.h
*/
#include <iostream>
#include "primary_character.h"
#include "character_setup.h"
#include "support.h"

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
    // sets name, gender, race, and character class
    // ingame_entity.h
    //set_information(); 
    // sets primary stats- primary attributes and secondary attributes
    // character_setup.h
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

void Primary_character::print_header_stats()
{
    std::cout << "Name:" << get_name() << " Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.experience_points() << "/" 
            << m_innate_character_stats.experience_points_needed() << std::endl;
}

void Primary_character::print_stats()
{
    std::cout << "Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
    std::cout << "Exp: " << m_innate_character_stats.experience_points() << "/" << 
        m_innate_character_stats.experience_points_needed() << std::endl;
    std::cout << "Strength: " << m_innate_character_stats.strength() << std::endl;
    std::cout << "Leadership: " << m_innate_character_stats.leadership() << std::endl;
    std::cout << "Intelligence: " << m_innate_character_stats.intelligence() << std::endl;
    std::cout << "Character: " << m_innate_character_stats.character() << std::endl;
    std::cout << "Endurance: " << m_innate_character_stats.endurance() << std::endl;
}

bool Primary_character::turn(std::vector<Ingame_entity_human*>& turn_order)
{
    // variable tracking if the turn resulted in a successful action i.e. 
    // if has status condition like stun and can't attack the f_success is false
    bool f_success = false, f_back = true;
    // check if current character is dead or not
    if(current_health_total() > 0)
    {
        while(f_back)
        {
            // TO BE IMPLEMENTED-Check for status condition
            // Assume if got this far, this turn is "successful"
            f_success = true;
            // checks if player selects an action that directly affects the current player
            // if it is a move or flee action then the select_action function will resolve it
            if(m_possible_actions.select_actions())
            {
                // if it is not a move or flee then it's some form of an offensive action
                // which will result in another prompt for the user to select an attack
                f_back = action(turn_order);
            }
        }
    }
    
    // return true if the character was able to successfully complete a turn
	// else return false if for some reason the player couldn't take their turn
    return f_success;
}

bool Primary_character::action(std::vector<Ingame_entity_human*>& turn_order)
{
    // return value
    bool back = false;
    
    // prompts the user for what offensive action they would like to do
    std::cout << "What action would you like to perform?" << std::endl;
    // m_character_possible_attacks is a struct List_of_attacks described in attacks.h
    m_character_possible_attacks.list_attacks();
    std::cout << "4.Back" << std::endl << "Input:";
    int f_select_actions = get_number_from_user(1, 4);
    if(f_select_actions == ATTACK)
    {
        std::cout << "Primary_attack" << std::endl;
        // attack();
    }
    else if(f_select_actions == ULTIMATE)
    {
        std::cout << "Ultimate_attack" << std::endl;
    }
    else if(f_select_actions == ITEM)
    {
        std::cout << "Items" << std::endl;
    }
    else if(f_select_actions == 4)
    {
        back = true;
    }
    
    // returns true if the character selects an action, returns false if the
	// character wants to return to the previous prompt
    return back;
}