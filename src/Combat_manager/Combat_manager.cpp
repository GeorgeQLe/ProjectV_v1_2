/*  Copyright 2017 George Le
    Definitions of functions declared in combat.h and defines functions to be
    used specifically with the functions in combat.h ONLY!!!
*/
#include <iostream>
#include "Combat_manager/Combat_manager.h"
#include "Support/random.h"
#include "Support/vector_quicksort.h"

CCombatManager::CCombatManager()
{
    // Empty constructor
}

void CCombatManager::CreateTurnOrder(const std::vector<std::shared_ptr<CPrimaryCharacter>>& list_of_characters, 
                                const std::vector<std::shared_ptr<CHostile>>& list_of_hostiles)
{
    // if turn_order isn't empty then clear it of its contents
    if(!m_turn_order.empty())
    {
        m_turn_order.clear();
    }
    
    // push all the hostiles into the turn order
    for(unsigned int i = 0; i != list_of_hostiles.size(); ++i)
    {
        m_turn_order.push_back(list_of_hostiles.at(i));
    }
    // push all the primary_characters into the turn order
    for(unsigned int i = 0; i != list_of_characters.size(); ++i)
    {
        m_turn_order.push_back(list_of_characters.at(i));
    }
    
    // sort the turn order from fastest characters to slowest characters
    // implements quick sort to sort player characters -> defined in include/Support/vector_quicksort.h
    quicksort(m_turn_order, 0, m_turn_order.size(), CCombatEntity::SSpeedCompare());
}

Result CCombatManager::SingleTurn(unsigned int number_of_player_characters, unsigned int number_of_hostiles)
{
    // return value of the function, set initially to fighting
    Result f_victory_or_loss = FIGHTING;
    
    // if count of players not able to take actions is equal to
    // number of player characters, check if player team all died
    // same for hostile_counter
    unsigned int f_player_counter = 0, f_hostile_counter = 0;
    
    // boolean to track if the entity's turn was successful or not
    bool f_success = false;
    
    // Print out the stats of all entities in the turn_order
    // Shows the player what the status of all the entities involved
    // in combat fared after the last turn, if first turn then shows
    // the player what they are facing and their own status
    for(auto it = m_turn_order.begin(); it != m_turn_order.end(); ++it)
    {
        (*it)->PrintHeaderStats();
    }
    
    // loop to let every object take a turn
    for(auto it = m_turn_order.begin(); it != m_turn_order.end(); ++it)
    {
        if((*it)->CheckStatus())
        {
            // iterators are primary_characters or hostiles found in their respective files
            // print_header_stats should be overloaded for primary_characters and hostiles
            std::cout << "It is " << (*it)->Name() << "'s turn!\n";
            // what ugly syntax double dereference
            // turn should be overloaded for primary_characters and hostiles
            f_success = (*it)->Turn(m_turn_order);
        }
        
        // if the entity did not have a successful turn
        if(f_success == false && (*it)->IsHostile() == false)
        {
            // this counter tracks how many primary_characters failed to take an action
            ++f_player_counter;
        }
        // if the entity did not have a successful turn and is a hostile
        else if(f_success == false && (*it)->IsHostile())
        {
            // this counter tracks how many hostile_characters failed to take an action
            ++f_hostile_counter;
        }
        
        // if the entirety of the player's party cannot attack or take any other action
        if(f_player_counter == number_of_player_characters)
        {
            // sets victory_or_loss to POTENTIAL_PLAYER_WIPE so the battle functions can
            // check to see if the player team is all dead
            f_victory_or_loss = POTENTIAL_PLAYER_WIPE;
        }
        // if the entirety of the hostiles cannot attack or take any other action
        else if(f_hostile_counter == number_of_hostiles)
        {
            // sets victory_or_loss to POTENTIAL_HOSTILE_WIPE so the battle functions can
            // check to see if the hostiles are all dead
            f_victory_or_loss = POTENTIAL_HOSTILE_WIPE;
        }
    }
    
    // should either return fighting, potential_player_wipe, or potential_hostile_wipe
    return f_victory_or_loss;
}

Result CCombatManager::PartyVPartyBattle(std::vector<std::shared_ptr<CPrimaryCharacter>>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result f_victory_or_loss = NOT_STARTED;
    
    // player wipe or hostile wipe
    bool f_player_wipe, f_hostile_wipe; 
    
    // creates a vector to store hostiles
    std::vector<std::shared_ptr<CHostile>> list_of_hostiles;
    
    // adds hostiles to the list of hostiles
    add_hostile(list_of_hostiles, 1, enum_difficult_converted_to_int);
    
    // initializes a turn counter 
    unsigned int f_round_counter = 1;
    
    // sets up the turn order for combat
    CreateTurnOrder(list_of_characters, list_of_hostiles);
    
    // main combat loop
    do
    {
        std::cout << "Start of round " << f_round_counter << "!" << std::endl;
        
        // plays out one turn of the current encounter
        f_victory_or_loss = SingleTurn(list_of_characters.size(), list_of_hostiles.size());
        
        // if speed change then redo the turn order
        
        // check if player lost or won respectively
        f_player_wipe = CheckPlayerHealths(list_of_characters);
        f_hostile_wipe = CheckHostileHealths(list_of_hostiles);
        if(f_player_wipe)
        {
            // if the entire player team wiped then game over
            f_victory_or_loss = PLAYER_DEATH;
        }
        else if(f_hostile_wipe)
        {
            // if the player defeats all hostiles then victory
            f_victory_or_loss = PLAYER_VICTORY;
        }
        
        ++f_round_counter;
    }while(f_victory_or_loss == FIGHTING || f_victory_or_loss == POTENTIAL_HOSTILE_WIPE || f_victory_or_loss == POTENTIAL_PLAYER_WIPE);
    
    // should either return fighting, player_victory or player_death
    return f_victory_or_loss;
}

bool CCombatManager::CheckPlayerHealths(std::vector<std::shared_ptr<CPrimaryCharacter>> list_of_characters)
{
    unsigned int f_counter = 0;
    for(auto it = list_of_characters.begin(); it != list_of_characters.end(); it++)
    {
        // if character is dead
        if((*it)->CurrentHealthTotal() <= 0)
        {
            // increment the death counter
            ++f_counter;
        }
    }
    
    // if the number of dead player-controlled characters is equal to the
    // number of party characters
    if(f_counter == list_of_characters.size())
    {
        // return true that the player lost
        return true;
    }
    
    // return false for a false flag
    return false;
}
    
bool CCombatManager::CheckHostileHealths(std::vector<std::shared_ptr<CHostile>> list_of_hostiles)
{
    unsigned int f_counter = 0;
    for(auto it = list_of_hostiles.begin(); it != list_of_hostiles.end(); it++)
    {
        // if the hostile is dead
        if((*it)->CurrentHealthTotal() == 0)
        {
            // increment the death counter
            ++f_counter;
        }
    }
    
    // if the number of dead hostiles is equal to the number of hostiles
    if(f_counter == list_of_hostiles.size())
    {
        // return true that the player won
        return true;
    }
    
    // return false for false flag
    return false;
}