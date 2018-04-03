# ProjectV
Text based RPG-adventure game written in C++
Copyright 2016 George Le

Years after a catastrophic accident on the private colony world, Diadal, life has almost returned to normal, if not for the mess of factions vying for control over the planet. You are one of the survivors of the calamity, waking up from cryo-sleep fifty years later. Possessing cybernetic augmentations that have become extremely rare and valuable after the accident, you have the edge to influence the fate of your new home planet. But be careful, since with that great power, there come many wishing to have you on their side or to destroy you. 

   Who can you trust? 
  
Welcome to the world of Diadal, a colony built by Hungarian settlers with the assistance of the UKCS (United Kingdom Colonial Services).
A terraformed exoplanet, Diadal, is a temperate planet on the edge of its system's habitable zone. With a lengthy summer season, Diadal was quick to capitalize on its fertile land and favorable weather, formulating a strong colonial economy built on agriculture. However, two decades after its founding in 2257, a calamity struck the planet. The incident long forgotten scorched the land and destroyed the space fleet defending the once bountiful planet. 

The story should have ended there with the destruction of an entire local civilization.

   But of course, humanity has survived much worse.

Notation notes: Code is written in snake_case and utilizes hungarian notation
    
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

Project Victory Changelog

Project Victory Alpha version 1.0
      Date: Sometime Early 2016
      Version objective: 1. Written in C <--Ignore it
    
Project Victory Alpha version 1.1
      Date: Sometime Summer 2016
      Version objective: 1. Wrote game.cpp and projectV.h and .cpp
                            a. Changed projectV to Diadal to suit the game narrative

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
                            
Special Thanks To:

      Dmitry "dsodintsov" -For mentoring on software structure and help on specific code problems and errors.
