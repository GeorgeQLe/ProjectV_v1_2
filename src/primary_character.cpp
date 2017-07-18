/*  Copyright 2017 George Le
    Definitions of functions declared in primary_character.h
*/
#include <iostream>
#include "primary_character.h"
#include "character_setup.h"
#include "support.h"

Primary_character::Primary_character(bool player) 
                : Combat_entity{"Adam", MALE, WHITE, CAPTAIN}, m_player_character(player)
{
    character_creator();
}

void Primary_character::character_creator()
{
    Factory_player_characters f_creator;
	f_creator.secondary_stats_setup(job(), m_learned_character_stats);
	equip_weapons();
}

bool Primary_character::equip_weapons()
{
    // if player can use the weapon
    if(true)
    {
        // equip the weapon
        
        // demo only
        m_character_possible_attacks.update_damage(strength(), 5);
        
        // return true for success
        return true;
    }
    return false;
}

void Primary_character::reduce_or_increase_reputation(bool increase, int amount)
{
    if(increase == false)
    {
        reduce_or_increase_reputation(increase, amount);
    }
    else if(increase)
    {
        reduce_or_increase_reputation(increase, amount);
    }
}

bool Primary_character::turn(std::vector<std::shared_ptr<Combat_entity>>& turn_order)
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

bool Primary_character::action(std::vector<std::shared_ptr<Combat_entity>>& turn_order)
{
    // return value
    bool f_back = false;
    
    // prompts the user for what offensive action they would like to do
    std::cout << "What action would you like to perform?" << std::endl;
    
    // m_character_possible_attacks is a struct List_of_attacks described in attacks.h
    m_character_possible_attacks.list_attacks();
    std::cout << "4.Back" << std::endl << "Input:";
    
    // gets the user's selection
    int f_select_actions = get_number_from_user(1, 4);
    
    // selects a target, select_target declared in combat_entity.h
    int f_target_index = select_target(turn_order);
    
    // evaluates the user's selection of an action
    if(f_select_actions == ATTACK)
    {
        std::cout << "Gets here" << std::endl;
        attack(turn_order.at(f_target_index));
    }
    else if(f_select_actions == ULTIMATE)
    {
        std::cout << "Ultimate_attack" << std::endl;
        ultimate_attacks(turn_order.at(f_target_index));
    }
    else if(f_select_actions == ITEM)
    {
        std::cout << "Items" << std::endl;
        items(turn_order.at(f_target_index));
    }
    else if(f_select_actions == 4)
    {
        f_back = true;
    }
    
    // returns true if the character selects an action, returns false if the
	// character wants to return to the previous prompt
    return f_back;
}

bool Primary_character::attack(std::shared_ptr<Combat_entity> target)
{
    return target->damage_entity(m_character_possible_attacks.m_primary_attack.damage());
}

bool Primary_character::ultimate_attacks(std::shared_ptr<Combat_entity> target)
{
    bool f_success;
    
    if(m_character_possible_attacks.pm_ult->usable())
    {
        f_success = target->damage_entity(m_character_possible_attacks.pm_ult->damage());
    }
    else
    {
        f_success = false;
        std::cout << "Your ultimate attack is not available!\n";
    }
    
    return f_success;
}

bool Primary_character::items(std::shared_ptr<Combat_entity> target)
{
    bool f_success;
    
    if(m_character_possible_attacks.pm_use_offensive_item->usable())
    {
        f_success = target->damage_entity(m_character_possible_attacks.pm_use_offensive_item->damage());
    }
    else
    {
        f_success = false;
        std::cout << "You have no items to use!\n";
    }
    
    return f_success;
}