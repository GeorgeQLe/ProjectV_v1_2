/*  Copyright 2017 George Le
    Declaration of Hostile base class
    
    Declaration:
        Classes:
            -Hostile
*/
#ifndef HOSTILE_H
#define HOSTILE_H

#include <string>
#include <vector>
#include "ingame_entity.h"
#include "primary_stats.h"
#include "actions.h"
#include "basic_state_AI.h"

// test enemy
class Hostile : public Ingame_entity_human
{
    public:
    Hostile() : Ingame_entity_human("Dummy", 1, 1, 1, true), m_hostile_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) { get_AI(); }
    Hostile(std::string name, int gender, int race, int job, int strength, int leadership, int intelligence, int character,
            int endurance, unsigned int level, unsigned int total_health, int current_health_total, unsigned int defense,
            unsigned int speed);
    ~Hostile() { delete mp_AI_system; }
    
    // overloading the virtual function left pure in the class Ingame_entity_human 
    virtual unsigned int speed() const { return m_hostile_stats.speed(); }
    
    // four functions for inheriting classes to override... please override them
    virtual void update();
    virtual void attack();
    virtual void move();
    virtual void flee();
    
    // calls this function when the hostile takes damage
	bool damage_entity(int amount_of_damage);
    
    private:
    // function to recieve an AI system
    void get_AI() { mp_AI_system = new State_machine<Hostile>(this); }
    
    Primary_stats m_hostile_stats;
    Actions m_potiential_actions;
    
    // the hostile's AI (brain)
    State_machine<Hostile>* mp_AI_system;
};

//adds hostiles to a list of hostile characters to be used in combat
void add_hostile(std::vector<Hostile*>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int);

#endif