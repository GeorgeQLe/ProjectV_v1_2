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
                            
    Notation notes: Code is written in a mixture of snake_case and PascalCase and utilizes hungarian notation
                    Notation is strongly based on Google's C++ style guide with some variations
    
        Ex. 
        (variables)- snake_case
            int this_is_an_int;
            int* p_this_is_an_int_pointer;
            int f_this_is_a_function_variable;
            Enumerated types(enums) are written in ALL CAPS
            enum Example { eExample_ZERO, eExample_ONE, eExample_TWO = 3};
            
        (struct)- PascalCase
            struct SExampleStruct
            {
                  
            };
            
        (class)- PascalCase
            class CExampleClass
            {
                public:
                const CExampleClass c_example_class;
            (function)- PascalCase
                public:
                void ThisIsAFunction();
            
            (member_variable)
                private:
                int m_this_is_a_member_variable;
                static int sm_this_is_a_static_member_variable;
                const int cm_this_is_a_const_member_variable;
                int* pm_this_is_a_pointer_to_a_member_variable;
            }
*/
#include "Diadal/Diadal.h"

int main()
{
    // initializing an instance of the game
    CDiadal f_game_instance;
    
    // game loop in main
    // TitleMenu returns true if the player wants to play the game
    // or continue playing the game and returns false if the player
    // wants to quit
    // while(game_instance.TitleMenu())
    // {
    //     // actual game loop
    //     game_instance.GameLoop();
    // }
    
    f_game_instance.NewGame();
}