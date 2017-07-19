/*  Copyright 2017 George Le
    Definition of member functions declared in Flee_action.cpp
*/
#include <iostream>
#include "Actions/Flee_action.h"

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