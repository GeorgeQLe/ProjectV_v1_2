/*  Copyright 2017 George Le
    Definition of turn-based combat system between Primary characters and created hostiles
*/
#ifndef COMBAT_H
#define COMBAT_H
#include <map>
#include <vector>
#include "primary_character.h"
#include "hostile.h"

enum Result { NOT_STARTED = -1, FIGHTING, PLAYER_DEATH, PLAYER_VICTORY, TIE};

std::vector<Ingame_entity_human*> turn_order(const std::map<int, Primary_character*>& list_of_characters, 
                                            const std::map<int, Hostile*>& list_of_hostiles);

// Function that plays a 1v1 turn-based battle between a PLAYER-controlled primary_character and one hostile
// If the PLAYER-controlled party has more than one primary_character then call a different function
Result one_v_one_duel(std::vector<Ingame_entity_human*>& list_of_combatants);

Result party_v_one_duel(std::map<int, Primary_character*>& list_of_characters, int enum_difficult_converted_to_int);

#endif