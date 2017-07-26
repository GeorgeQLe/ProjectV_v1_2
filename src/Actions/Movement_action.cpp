/*  Copyright 2017 George Le
    Definitions of member functions in Movement_action.h
*/
#include <iostream>
#include "Actions/Movement_action.h"

CMovementAction::CMovementAction() : can_move(true) 
{
    
}

CMovementAction::~CMovementAction() 
{
    
}

void CMovementAction::Move()
{
    if(can_move == true)
    {
        std::cout << "Move\n";
    }
}