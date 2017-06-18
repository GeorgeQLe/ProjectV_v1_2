/*	Copyright 2016 George Le
    Definition of functions declared in hostile.h
*/
#include "hostile.h"

void Hostile::update()
{
    // TO BE IMPLEMENTED
}

void Hostile::attack()
{
    // TO BE IMPLEMENTED
}

void Hostile::move()
{
    // TO BE IMPLEMENTED
}

void Hostile::flee()
{
    // TO BE IMPLEMENTED
}

void add_hostile(std::map<int, Hostile>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int)
{
    for(int i = 0; i < number_of_hostiles; i++)
    {
        // generates random hostile and inserts it into the list of hostiles
    }
}