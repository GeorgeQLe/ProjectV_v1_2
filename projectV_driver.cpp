/*  George Le
    project Victory Alpha version 1.2
    Date: 12/16/16 - 
    
    Version objective: 1. Character redesign to suit OOP design patterns (DESIGNING)
    						a. Ingame entity(controllable) (base) (DONE-ISH)
    						    -Character creation (IN PROGRESS)
    						b. NPC(derived)
    						c. Allies (controllable)(derived)
    						d. Hostiles (base)
    						e. Instance Allies
                       2. Combat system
                            a.Player combat
                            b.Player gear modifier
                            c.Player can heal/use items
                            d.Player can flee/can use modified flee action
                            e.Hostiles attack
                            f.Hostiles heal/use items
                            g.Random number generator->attack accuracy hit/miss
                       3. Travel system (NOT STARTED)
                            a.Travel a to b 
                            b.Initiate combat from travels 
                            c.Random NPC encounter->noncombat
                            d.Money system
                            e.Trade with caravan
                            
    Notation notes: Code is written in snake_case and utilizes hungarian notation
    
        Ex. 
            int this_is_an_int;
            int* p_this_is_an_int_pointer;
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

using namespace std;

int main()
{
    Diadal game_instance;
    
    while(game_instance.game_menu())
    {
        game_instance.game_loop();
    }
}