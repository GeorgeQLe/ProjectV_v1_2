/*  Copyright 2017 George Le
    Definition of turn-based combat system between Primary characters and created hostiles
    
    Declaration:
        -enumerated types Result
        Functions:
            -std::vector<Ingame_entity_human*> turn_order(const std::vector<Primary_character*>& list_of_characters, 
                                            const std::vector<Hostile*>& list_of_hostiles)
            -Result single_turn(std::vector<Ingame_entity_human*>& list_of_combatants, unsigned int number_of_player_characters)
            -Result one_v_one_battle(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
            -Result party_v_party_battle(std::vector<Primary_character*>& list_of_characters, int enum_difficult_converted_to_int)
*/

#ifndef COMBAT_H
#define COMBAT_H

#include <memory>
#include <vector>
#include <map>
#include "primary_character.h"
#include "hostile.h"

enum Result { NOT_STARTED = -1, FIGHTING, PLAYER_DEATH, PLAYER_VICTORY, TIE, POTENTIAL_PLAYER_WIPE, POTENTIAL_HOSTILE_WIPE};

class Combat_manager
{
    public:
    Combat_manager() {}
    
    // merge the two vectors of list of player characters and hostiles into a third vector turn order and
    // combat will affect this vector which contains pointers to the original party characters
    void turn_order(const std::vector<std::shared_ptr<Primary_character>>& list_of_characters, 
                    const std::vector<std::shared_ptr<Hostile>>& list_of_hostiles);
    
    // Function that plays out one turn of combat
    Result single_turn(unsigned int number_of_player_characters, unsigned int number_of_hostiles);
    
    // experimental battle with a similar xcom style with elements of combat in pokemon  
    Result party_v_party_battle(std::vector<std::shared_ptr<Primary_character>>& list_of_characters, int enum_difficult_converted_to_int);
    
    // two following functions check to see if the potential player or hostile wipes are a reality or not
    bool check_player_healths(std::vector<std::shared_ptr<Primary_character>> list_of_characters);
    
    bool check_hostile_healths(std::vector<std::shared_ptr<Hostile>> list_of_hostiles);
    
    private:
    // standard turn order used for combat
    std::vector<std::shared_ptr<Combat_entity>> m_turn_order;
    
    // temporary turn order used for any modifications to the main turn order
    std::vector<std::shared_ptr<Combat_entity>> m_temp_turn_order;
    
    // object pool to store hostiles so you don't have to continuously create more and more hostile objects
    std::map<int, std::vector<std::shared_ptr<Hostile>>> m_object_pool;
};

#endif