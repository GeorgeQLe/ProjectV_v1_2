/*  Copyright 2017 George Le
    Definitions of functions declared in combat.h and defines functions to be
    used specifically with the functions in combat.h ONLY!!!
*/
#include <iostream>
#include "combat.h"
#include "random.h"
#include "vector_quicksort.h"

void Combat_manager::turn_order(const std::vector<Primary_character*>& list_of_characters, 
                                            const std::vector<Hostile*>& list_of_hostiles)
{
    if(!m_turn_order.empty())
    {
        m_turn_order.clear();
    }
    
    // push all the primary_characters into the turn order
    for(unsigned int i = 0; i != list_of_characters.size(); i++)
    {
        m_turn_order.push_back(list_of_characters.at(i));
    }
    
    // push all the hostiles into the turn order
    for(unsigned int i = 0; i != list_of_hostiles.size(); i++)
    {
        m_turn_order.push_back(list_of_hostiles.at(i));
    }
    
    // sort the turn order from fastest characters to slowest characters
    // implements quick sort to sort player characters
    quicksort(m_turn_order, 0, m_turn_order.size(), Ingame_entity_human::speed_compare());
}

Result Combat_manager::single_turn(unsigned int number_of_player_characters, 
                    unsigned int number_of_hostiles)
{
    // return value of the function, set initially to fighting
    Result victory_or_loss = FIGHTING;
    
    // if count of players not able to take actions is equal to
    // number of player characters, check if player team all died
    // same for hostile_counter
    unsigned int player_counter = 0, hostile_counter = 0;
    
    // boolean to track if the entity's turn was successful or not
    bool success = false;
    
    // loop to let every object take a turn
    for(auto it = m_turn_order.begin(); it != m_turn_order.end(); it++)
    {
        // iterators are primary_characters or hostiles found in their respective files
        // print_header_stats should be overloaded for primary_characters and hostiles
        (*it)->print_header_stats();
        // what ugly syntax double dereference
        // turn should be overloaded for primary_characters and hostiles
        success = (*it)->turn(m_turn_order);
        // if the entity did not have a successful turn
        if(success == false && (*it)->is_hostile() == false)
        {
            // this counter tracks how many primary_characters failed to take an action
            ++player_counter;
        }
        // if the entity did not have a successful turn and is a hostile
        else if(success == false && (*it)->is_hostile())
        {
            // this counter tracks how many hostile_characters failed to take an action
            ++hostile_counter;
        }
    }
    
    // if the entirety of the player's party cannot attack or take any other action
    if(player_counter == number_of_player_characters)
    {
        // sets victory_or_loss to POTENTIAL_PLAYER_WIPE so the battle functions can
        // check to see if the player team is all dead
        victory_or_loss = POTENTIAL_PLAYER_WIPE;
    }
    // if the entirety of the hostiles cannot attack or take any other action
    else if(hostile_counter == number_of_hostiles)
    {
        // sets victory_or_loss to POTENTIAL_HOSTILE_WIPE so the battle functions can
        // check to see if the hostiles are all dead
        victory_or_loss = POTENTIAL_HOSTILE_WIPE;
    }
    
    // should either return fighting, potential_player_wipe, or potential_hostile_wipe
    return victory_or_loss;
}

Result Combat_manager::one_v_one_battle(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    
    // checks if it's really a one v one fight
    if(list_of_characters.size() != 1)
    {
        // call another combat function depending on the size of your party
        victory_or_loss = party_v_party_battle(list_of_characters, enum_difficult_converted_to_int);   
    }
    
    // creates a vector to store hostiles at a specific index
    std::vector<Hostile*> list_of_hostiles;
    
    // adds hostiles to the list of hostiles
    add_hostile(list_of_hostiles, roll_d_four(), enum_difficult_converted_to_int);
    
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    
    // sets up the turn order for the game
    turn_order(list_of_characters, list_of_hostiles);
    
    // main combat loop
    while(victory_or_loss == NOT_STARTED || victory_or_loss == FIGHTING)
    {
        // plays out one turn of the current encounter
        victory_or_loss = single_turn(list_of_characters.size(), list_of_hostiles.size());
        
        // if POTENTIAL_PLAYER_WIPE or POTENTIAL_HOSTILE_WIPE, check if player lost or won respectively
        
        
        // if speed change then check and potentially redo the turn order
        
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 3 && victory_or_loss == NOT_STARTED)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        turn_counter++;
    }
    
    // should either return fighting, player_victory or player_death
    return victory_or_loss;
}

Result Combat_manager::party_v_party_battle(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    
    // creates a vector to store hostiles
    std::vector<Hostile*> list_of_hostiles;
    
    // adds hostiles to the list of hostiles
    add_hostile(list_of_hostiles, roll_d_four(), enum_difficult_converted_to_int);
    
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    
    // sets up the turn order for combat
    turn_order(list_of_characters, list_of_hostiles);
    
    // main combat loop
    while(victory_or_loss == NOT_STARTED || victory_or_loss == FIGHTING)
    {
        // plays out one turn of the current encounter
        victory_or_loss = single_turn(list_of_characters.size(), list_of_hostiles.size());
        
        // if POTENTIAL_PLAYER_WIPE or POTENTIAL_HOSTILE_WIPE, check if player lost or won respectively
        
        
        // if speed change then redo the turn order
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 3 && victory_or_loss == NOT_STARTED)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        ++turn_counter;
    }
    
    // should either return fighting, player_victory or player_death
    return victory_or_loss;
}