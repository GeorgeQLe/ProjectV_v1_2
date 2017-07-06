/*  Copyright 2017 George Le
    Declaration of Hostile base class
    
    Declaration:
        -
*/
#ifndef HOSTILE_H
#define HOSTILE_H

#include <string>
#include <map>
#include "ingame_entity.h"
#include "primary_stats.h"
#include "actions.h"
#include "basic_state_AI.h"

// test enemy
class Hostile : public Ingame_entity_human
{
    public:
    Hostile() : Ingame_entity_human("Dummy", 1, 1, 1), m_hostile_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) {}    
    ~Hostile() { delete mp_AI_system; }
    // four functions for inheriting classes to override... please override them
    virtual void update();
    virtual void attack();
    virtual void move();
    virtual void flee();
    
    private:
    // function to recieve an AI system
    void get_AI() { mp_AI_system = new State_machine<Hostile>(this); }
    
    // 
    bool is_hostile;
    
    Primary_stats m_hostile_stats;
    Actions m_potiential_actions;
    
    State_machine<Hostile>* mp_AI_system;
};

//adds hostiles to a list of hostile characters to be used in combat
void add_hostile(std::map<int, Hostile>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int);

#endif