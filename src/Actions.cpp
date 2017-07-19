/*  Copyright 2017 George Le
    Definitions of functions declared in actions.h
*/
#include <iostream>
#include "Actions.h"
#include "support.h"

Actions::Actions()
{
    list_of_action_names.push_back("1. Action");
    list_of_action_names.push_back("2. Move");
    list_of_action_names.push_back("3. Flee");
}

Actions::~Actions()
{
    // Empty destructor
}

void Actions::list_possible_actions()
{
    for(auto it = list_of_action_names.begin(); it != list_of_action_names.end(); it++)
    {
        std::cout << *it << "\n";
    }
}

bool Actions::select_actions()
{
    std::cout << "What would you like to do?\n";
    list_possible_actions();
    std::cout << "Input:";
    int f_user_choice = get_number_from_user(1, 4);
    bool attack = false;
    switch(f_user_choice)
    {
        case 1:
        // returns true so that the calling entity can resolve its own attacks
        attack = true;
        break;
        case 2:
        move();
        break;
        case 3:
        if(flee())
        {
            std::cout << "You successful fled!\n";
        }
        else
        {
            std::cout << "You failed to run away!\n";
        }
        break;
        default:
        break;
    }
    return attack;
}