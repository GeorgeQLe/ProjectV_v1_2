/*  Copyright 2017 George Le
    Declaration of ingame entities' actions
    
    Declarations:
        Enum:
            -Action_type
        
        Classes:
            -Movement_action
            -Flee_action
            -Actions
*/
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <vector>
#include "attacks.h"

class Movement_action
{
    public:
    Movement_action() : can_move(true) {}
    // function that controls ingame entity or hostile movement
    void move();
    
    private:
    bool can_move;
};

class Flee_action
{
    public:
    Flee_action() : can_flee(true) {}
    
    // function that controls the ingame entity or hostile flee action
    // returns true if flee is successful and false if failed
    bool flee();
    
    private:
    bool can_flee;
};

class Actions : public Movement_action, public Flee_action
{
    public:
    Actions();
    
    // Prints to the screen all of the possible actions available to the entity
    void list_possible_actions();
    // Used in conjuction with above function to recieve user input on which 
    // action they want to perform then evaluates it if it is move or flee.
    // Returns true if the user wants to attack or use item, false if anything else
    bool select_actions();
    
    private:
    std::vector<std::string> list_of_action_names;
    // TO BE DESIGNED
    // class to interact with Inventory in Inventory.h
};

#endif