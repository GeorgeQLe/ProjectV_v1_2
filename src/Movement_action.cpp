/*  Copyright 2017 George Le
    Definitions of member functions in Movement_action.h
*/
#include <iostream>
#include "Movement_action.h"

Movement_action::Movement_action() : can_move(true) 
{
    
}

Movement_action::~Movement_action() 
{
    
}

void Movement_action::move()
{
    if(can_move == true)
    {
        std::cout << "Move\n";
    }
}