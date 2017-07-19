/*  Copyright 2017 George Le
    Declaration of Hostile base class
    
    Declaration:
        Classes:
            -Hostile
*/
#ifndef HOSTILE_H
#define HOSTILE_H

#include <vector>
#include <memory>
#include "Actions/Actions.h"
#include "AI/Base_state.h"
#include "AI/State_machine.h"
#include "Entity/Combat_entity.h"
#include "List_of_attacks.h"

// test enemy
class Hostile : public Combat_entity
{
    public:
    Hostile();
    Hostile(int difficulty);
    ~Hostile();
    
    // combat functions
    
    // overloading function in combat_entity to print out the hostile's header stats
    virtual void print_header_stats();
    
    // overloading function in combat_entity to take a turn for the hostile
    virtual bool turn(std::vector<std::shared_ptr<Combat_entity>>& turn_order);
    
    // four functions for inheriting classes to override... please override them
    virtual bool update();
    virtual bool attack();
    virtual bool move();
    virtual bool flee();
    
    // function to select something to attack
    virtual void get_target(std::vector<std::shared_ptr<Combat_entity>> list_of_targets);

    private:
    // declared in actions.h
    Actions m_potiential_actions;
    
    // declared in attacks.h
    List_of_attacks m_hostile_attacks;
    
    // the hostile's AI (brain)
    std::shared_ptr<State_machine<Hostile>> mp_AI_system;
    
    // reference to the hostile's target
    std::weak_ptr<Combat_entity> m_target;
    
    // set initially to false, call flee() to set to true, then second call to flee successfully flee
    bool m_can_flee;
    
    // amount of experience points the player can earn by defeating this hostile
    unsigned int m_experience_points_granted;
};

//adds hostiles to a list of hostile characters to be used in combat
void add_hostile(std::vector<std::shared_ptr<Hostile>>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int);

#endif