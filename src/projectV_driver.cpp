/*  Copyright 2016 George Le
    Project Victory Alpha version 1.2
    Date: 12/16/16 - 
    
    Version objective: 1. Character redesign to suit OOP design patterns (FINISHING)
    						a. Ingame entity(controllable) (base) (DONE-ISH)
    						    -Character creation (DONE-ISH) <- CUSTOM character creation delayed to v 1.3
    						b. NPC(derived) <- delayed to version 1.3
    						c. Allies (controllable)(derived) <- delayed to version 1.3
    						d. Hostiles (base) (DONE-ISH)
    						e. Instance Allies <- delayed to version 1.3
                       2. Combat system (IN PROGRESS)
                            a.Player combat (IN PROGRESS)
                            b.Player gear modifier <- delayed to version 1.4
                            c.Player can heal/use items <- delayed to version 1.4
                            d.Player can flee/can use modified flee action (IN PROGRESS)
                            e.Hostiles attack (IN PROGRESS)
                            f.Hostiles heal/use items <- delayed to version 1.4
                            g.Random number generator->attack accuracy hit/miss (IN PROGRESS)
                            
    Notation notes: Code is written in snake_case and utilizes hungarian notation
    
        Ex. 
            int this_is_an_int;
            int* p_this_is_an_int_pointer;
            int f_this_is_a_function_variable;
            Enumerated types(enums) are written in ALL CAPS
            enum Example { ZERO, ONE, TWO = 3};
            
            class Example
            {
                private:
                int m_this_is_a_member_variable;
                static int sm_this_is_a_static_member_variable;
                const int cm_this_is_a_const_member_variable;
                int* pm_this_is_a_pointer_to_a_member_variable;
            }
*/
#include "Diadal.h"

int main()
{
    Diadal game_instance;
    
    while(game_instance.game_menu())
    {
        game_instance.game_loop();
    }
}