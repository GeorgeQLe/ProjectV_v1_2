/*  Copyright 2017 George Le
    Declaration of Hostile base class and its member functions
*/
#ifndef HOSTILE_H
#define HOSTILE_H

#include <vector>
#include <memory>
#include "Actions/Actions.h"
#include "AI/Base_state.h"
#include "AI/State_machine.h"
#include "Attacks/List_of_attacks.h"
#include "Entity/Combat_entity.h"

// test enemy
class CHostile : public CCombatEntity
{
    public:
    CHostile();
    CHostile(int difficulty);
    ~CHostile();
    
    // combat functions
    
    // overloading function in combat_entity to print out the hostile's header stats
    virtual void PrintHeaderStats();
    
    // overloading function in combat_entity to take a turn for the hostile
    virtual bool Turn(std::vector<std::shared_ptr<CCombatEntity>>& turn_order);
    
    // four functions for inheriting classes to override... please override them
    virtual bool Update(std::vector<std::shared_ptr<CCombatEntity>> list_of_targets);
    virtual bool Attack();
    virtual bool Move();
    virtual bool Flee();
    
    // function to select something to attack
    virtual bool GetTarget(std::vector<std::shared_ptr<CCombatEntity>> list_of_targets);

    private:
    // declared in actions.h
    CActions m_potiential_actions;
    
    // declared in attacks.h
    SListOfAttacks m_hostile_attacks;
    
    // the hostile's AI (brain), declared in State_machine.h
    std::shared_ptr<CStateMachine<CHostile>> mp_AI_system;
    
    // reference to the hostile's target
    std::weak_ptr<CCombatEntity> m_target;
    
    // set initially to false, call flee() to set to true, then second call to flee successfully flee
    bool m_can_flee;
    
    // amount of experience points the player can earn by defeating this hostile
    unsigned int m_experience_points_granted;
};

//adds hostiles to a list of hostile characters to be used in combat
void add_hostile(std::vector<std::shared_ptr<CHostile>>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int);

#endif