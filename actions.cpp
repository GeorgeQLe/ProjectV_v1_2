/*  Copyright 2017 George Le

*/
#include <iostream>
#include "actions.h"
#include "support.h"

void Movement_action::move()
{
    if(can_move == true)
    {
        // TO BE IMPLEMENTED
        std::cout << "Move\n";
    }
}

bool Flee_action::flee()
{
    if(can_flee == true)
    {
        // TO BE IMPLEMENTED
        std::cout << "Flee\n";
        return true;
    }
    return false;
}

Actions::Actions()
{
    list_of_action_names.push_back("1. Attack");
    list_of_action_names.push_back("2. Move");
    list_of_action_names.push_back("3. Item");
    list_of_action_names.push_back("4. Flee");
}

Possible_actions Actions::select_actions()
{
    std::cout << "What action would you like to do?\n";
    list_possible_actions();
    return static_cast<Possible_actions>(get_number_from_user(1, 4));
}

void Actions::list_possible_actions()
{
    for(auto it = list_of_action_names.begin(); it != list_of_action_names.end(); it++)
    {
        std::cout << *it << "\n";
    }
}