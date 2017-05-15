/*  Copyright 2017 George Le

*/
#include <vector>
#include "combat.h"

Result one_v_one_single_turn(std::map<int, Primary_character*> list_of_characters, )

Result one_v_one_duel(std::map<int, Primary_character*> list_of_characters, int enum_difficult_converted_to_int)
{
    Result victory_or_loss = NOT_STARTED;
    int turn_counter = 0;
    while(victory_or_loss == NOT_STARTED)
    {
        
        if(turn_counter == 100)
        {
            victory_or_loss = TIE;
        }
        turn_counter++;
    }
    
    return victory_or_loss;
}