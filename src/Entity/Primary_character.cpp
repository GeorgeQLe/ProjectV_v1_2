/*  Copyright 2017 George Le
    Definitions of member functions declared in primary_character.h
*/
#include <iostream>
#include "Character_creation/Character_creation_command.h"
#include "Entity/Primary_character.h"
#include "Support/support.h"

CPrimaryCharacter::CPrimaryCharacter(bool player) 
                : CCombatEntity{"Adam", MALE, WHITE, CAPTAIN}, m_player_character(player)
{
    CharacterCreator();
}

void CPrimaryCharacter::CharacterCreator()
{
    CFactoryPlayerCharacters f_creator;
	f_creator.SecondaryStatsSetup(Job(), m_learned_character_stats);
	EquipWeapons();
}

bool CPrimaryCharacter::EquipWeapons()
{
    bool f_compatible = true;
    
    // check if the player can use the weapon, weapon in inventory class
    // f_compatible = 
    // if player can use the weapon
    if(f_compatible)
    {
        // equip the weapon TO BE DESIGNED
        
        // demo only
        m_character_possible_attacks.UpdateDamage(Strength(), 5);
        return true;
    }
    return false;
}

void CPrimaryCharacter::ReduceOrIncreaseReputation(bool increase, int amount)
{
    if(increase == false)
    {
        ReduceOrIncreaseReputation(increase, amount);
    }
    else if(increase)
    {
        ReduceOrIncreaseReputation(increase, amount);
    }
}

bool CPrimaryCharacter::Turn(std::vector<std::shared_ptr<CCombatEntity>>& turn_order)
{
    // variable tracking if the turn resulted in a successful action i.e. 
    // if has status condition like stun and can't attack the f_success is false
    bool f_success = false;
    bool f_back = true;
    
    // check if current character is dead or not
    if(CurrentHealthTotal() > 0)
    {
        while(f_back)
        {
            // TO BE IMPLEMENTED-Check for status condition
            
            // Assume if got this far, this turn is "successful"
            f_success = true;
            // checks if player selects an action that directly affects the current player
            // if it is a move or flee action then the select_action function will resolve it
            if(m_possible_actions.SelectActions())
            {
                // if it is not a move or flee then it's some form of an offensive action
                // which will result in another prompt for the user to select an attack
                f_back = Action(turn_order);
            }
        }
    }
    
    // return true if the character was able to successfully complete a turn
	// else return false if for some reason the player couldn't take their turn
    return f_success;
}

bool CPrimaryCharacter::Action(std::vector<std::shared_ptr<CCombatEntity>>& turn_order)
{
    // return value
    bool f_back = false;
    
    // prompts the user for what offensive action they would like to do
    std::cout << "What action would you like to perform?" << std::endl;
    
    // m_character_possible_attacks is a struct List_of_attacks described in attacks.h
    m_character_possible_attacks.ListAttacks();
    std::cout << "4.Back" << std::endl << "Input:";
    
    // gets the user's selection
    int f_select_actions = get_number_from_user(1, 4);
    
    // selects a target, select_target declared in combat_entity.h
    int f_target_index = SelectTarget(turn_order);
    
    // evaluates the user's selection of an action
    if(f_select_actions == ATTACK)
    {
        std::cout << "Gets here" << std::endl;
        Attack(turn_order.at(f_target_index));
    }
    else if(f_select_actions == ULTIMATE)
    {
        std::cout << "Ultimate_attack" << std::endl;
        UltimateAttacks(turn_order.at(f_target_index));
    }
    else if(f_select_actions == ITEM)
    {
        std::cout << "Items" << std::endl;
        Items(turn_order.at(f_target_index));
    }
    else if(f_select_actions == 4)
    {
        f_back = true;
    }
    
    // returns true if the character selects an action, returns false if the
	// character wants to return to the previous prompt
    return f_back;
}

bool CPrimaryCharacter::Attack(std::shared_ptr<CCombatEntity> target)
{
    return target->DamageEntity(m_character_possible_attacks.m_primary_attack->Damage());
}

bool CPrimaryCharacter::UltimateAttacks(std::shared_ptr<CCombatEntity> target)
{
    bool f_success;
    
    if(m_character_possible_attacks.pm_ult->Usable())
    {
        f_success = target->DamageEntity(m_character_possible_attacks.pm_ult->Damage());
    }
    else
    {
        f_success = false;
        std::cout << "Your ultimate attack is not available!\n";
    }
    
    return f_success;
}

bool CPrimaryCharacter::Items(std::shared_ptr<CCombatEntity> target)
{
    bool f_success = false;
    
    if(m_character_possible_attacks.pm_use_offensive_item->Usable())
    {
        f_success = target->DamageEntity(m_character_possible_attacks.pm_use_offensive_item->Damage());
    }
    else
    {
        f_success = false;
        std::cout << "You have no items to use!\n";
    }
    
    return f_success;
}