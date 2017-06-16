/*  Copyright 2017 George Le
    Definitions of functions declared in combat.h and defines functions to be
    used specifically with the functions in combat.h ONLY!!!
*/
#include "combat.h"

std::vector<Ingame_entity_human*> turn_order(const std::map<int, Primary_character*>& list_of_characters, 
                                            const std::map<int, Hostile*>& list_of_hostiles)
{
    std::vector<Ingame_entity_human*> f_turn_order;
    //Ingame_entity_human* p_fastest_character;
    unsigned int number_of_combatants = list_of_characters.size() + list_of_hostiles.size();
    
    // ensure that turn order has all combatants
    while(f_turn_order.size() != number_of_combatants)
    {
        // finds fastest player character and pushes them into the turn order 
        for(unsigned int i = 0; i < list_of_characters.size(); i++)
        {
            // compares two player characters and selects the character with the highest speed
        }
    }
    
    return f_turn_order;
}

Result single_turn(std::vector<Ingame_entity_human*>& list_of_combatants)
{
    // return value of the function, set initially to fighting
    Result victory_or_loss = FIGHTING;
    
    return victory_or_loss; // should either return fighting, player_victory or player_death
}

Result one_v_one_duel(std::vector<Ingame_entity_human*>& list_of_combatants)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    // creates a map to store hostiles at a specific index
    std::map<int, Hostile*> list_of_hostiles;
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    // turn order holds a reference to the player party and all hostiles
    std::vector<Ingame_entity_human*> f_list_of_combatants;
    
    // main combat loop
    while(victory_or_loss == NOT_STARTED)
    {
        // plays out one turn of the current encounter
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 100)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        turn_counter++;
    }
    return victory_or_loss;
}

Result party_v_one_duel(std::map<int, Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
{
    // initializes Result, an enum, to default value NOT_STARTED(-1)
    Result victory_or_loss = NOT_STARTED;
    // creates a map to store hostiles at a specific index
    std::map<int, Hostile*> list_of_hostiles;
    // initializes a turn counter 
    unsigned int turn_counter = 0;
    // turn order holds a reference to the player party and all hostiles
    std::vector<Ingame_entity_human*> list_of_combatants;
    
    // checks if it's really a one v one fight
    if(list_of_characters.size() != 1)
    {
        // call another combat function depending on the size of your party
        // TO BE DESIGNED
    }
    
    // main combat loop
    while(victory_or_loss == NOT_STARTED)
    {
        // plays out one turn of the current encounter
        
        // for demo only, way to leave while loop to avoid infinite loop
        if(turn_counter == 100)
        {
            victory_or_loss = PLAYER_DEATH;
        }
        turn_counter++;
    }
    return victory_or_loss;
}