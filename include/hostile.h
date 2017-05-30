/*  Copyright 2017 George Le
    Declaration of Hostile base class
    
    Declaration:
        -
*/
#ifndef HOSTILE_H
#define HOSTILE_H

#include <string>
#include "ingame_entity.h"
#include "primary_stats.h"
#include "actions.h"

// test enemy
class Hostile : public Ingame_entity_human
{
    public:
    Hostile() : Ingame_entity_human("Dummy", 1, 1, 1), hostile_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) {}    
    
    // three functions for inheriting classes to override... please override them
    virtual void attack();
    virtual void move();
    virtual void flee();
    
    protected:
    Primary_stats hostile_stats;
    Actions potiential_actions;
};

#endif