/*  Copyright 2017 George Le
    Declaration of Actions class and its member functions
    
    Declarations:
        Classes:
            -Movement_action
            -Actions
*/
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <vector>

#include "Movement_action.h"
#include "Flee_action.h"

class Actions : public Movement_action, public Flee_action
{
    public:
    Actions();
    ~Actions();
    
    // Prints to the screen all of the possible actions available to the entity
    void list_possible_actions();
    // Used in conjuction with above function to recieve user input on which 
    // action they want to perform then evaluates it if it is move or flee.
    // Returns true if the user wants to attack or use item, false if anything else
    bool select_actions();
    
    private:
    std::vector<std::string> list_of_action_names;
};

#endif