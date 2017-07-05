/*  Copyright 2017 George Le
    Definitions of functions declared in combat.h and defines functions to be
    used specifically with the functions in combat.h ONLY!!!
*/
#include "combat.h"
#include "vector_quicksort.h"

std::vector<Ingame_entity_human*> turn_order(const std::vector<Primary_character*>& list_of_characters, 
                                            const std::vector<Hostile*>& list_of_hostiles)
{
    // initialize the turn order
    std::vector<Ingame_entity_human*> f_turn_order;
    for(unsigned int i = 0; i != list_of_characters.size(); i++)
    {
        f_turn_order.push_back(list_of_characters.at(i));
    }
    for(unsigned int i = 0; i != list_of_hostiles.size(); i++)
    {
        f_turn_order.push_back(list_of_hostiles.at(i));
    }
    
    // sort the turn order from fastest characters to slowest characters
    // implements quick sort to sort player characters
    quicksort(f_turn_order, 0, f_turn_order.size(), Ingame_entity_human::speed_compare());
    
    return f_turn_order;
}

Result single_turn(std::vector<Ingame_entity_human*>& list_of_combatants, unsigned int number_of_player_characters)
{
    // return value of the function, set initially to fighting
    Result victory_or_loss = FIGHTING;
    // if count of players not able to take actions is equal to
    // number of player characters, check if player team all died
    unsigned int counter = 0;
    bool success = false;
    
    // loop to let every object take a turn
    for(auto it = list_of_combatants.begin(); it != list_of_combatants.end(); it++)
    {
        // what ugly syntax double dereference
        success = (*it)->turn();
        if(success == false)
        {
            ++counter;
        }
    }
    
    return victory_or_loss; // should either return fighting, player_victory or player_death
}

Result one_v_one_duel(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    // checks if it's really a one v one fight
    if(list_of_characters.size() != 1)
    {
        // call another combat function depending on the size of your party
        victory_or_loss = party_v_one_duel(list_of_characters, enum_difficult_converted_to_int);   
    }
    // creates a vector to store hostiles at a specific index
    std::vector<Hostile*> list_of_hostiles;
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    // turn order holds a reference to the player party and all hostiles
    std::vector<Ingame_entity_human*> f_list_of_combatants;
    // sets up the turn order for the game
    f_list_of_combatants = turn_order(list_of_characters, list_of_hostiles);
    // main combat loop
    while(victory_or_loss == NOT_STARTED)
    {
        // plays out one turn of the current encounter
        victory_or_loss = single_turn(f_list_of_combatants, f_list_of_combatants.size());
        // if speed change then redo the turn order
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 100)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        turn_counter++;
    }
    return victory_or_loss;
}

Result party_v_one_duel(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    // creates a map to store hostiles at a specific index
    std::vector<Hostile*> list_of_hostiles;
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    // turn order holds a reference to the player party and all hostiles
    std::vector<Ingame_entity_human*> f_list_of_combatants;
    // sets up the turn order for the game
    f_list_of_combatants = turn_order(list_of_characters, list_of_hostiles);
    // main combat loop
    while(victory_or_loss == NOT_STARTED)
    {
        // plays out one turn of the current encounter
        victory_or_loss = single_turn(f_list_of_combatants, f_list_of_combatants.size());
        // if speed change then redo the turn order
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 100)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        ++turn_counter;
    }
    return victory_or_loss;
}