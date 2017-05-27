/*  Copyright 2017 George Le

*/
#ifndef COMBAT_H
#define COMBAT_H
#include <map>
#include "primary_character.h"

enum Result { NOT_STARTED = -1, FIGHTING, PLAYER_DEATH, PLAYER_VICTORY, TIE}; 


Result one_v_one_duel(std::map<int, Primary_character*>& list_of_characters, int enum_difficult_converted_to_int);

#endif