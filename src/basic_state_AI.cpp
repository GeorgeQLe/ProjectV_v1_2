/*  Copyright 2017 George Le
    
    Defines functions declared in basic_hostile_AI.h
*/
#include <assert.h>
#include "basic_state_AI.h"

template<class Entity_type>
void State_machine<Entity_type>::update() const
{
    // if a global state is set then evaluate it
    if(mp_global_state)
    {
        mp_global_state->evaluate(mp_owner);
    }
    
    // same for the current state
    if(mp_currecnt_state)
    {
        mp_currecnt_state->evaluate(mp_owner);
    }
}

template<class Entity_type>
void State_machine<Entity_type>::change_state(Base_state<Entity_type>* p_new_state)
{
    assert(p_new_state && "State_machine trying to change to a null state");
    
    // record current state in previous state
    mp_previous_state = mp_currecnt_state;
    
    // call the current state's exit method
    mp_currecnt_state->exit(mp_owner);
    
    // change current state to a new state
    mp_currecnt_state = p_new_state;
    
    // call the new state's enter method
    mp_currecnt_state->enter(mp_owner);
}

template<class Entity_type>
void Idle_state<Entity_type>::enter(Entity_type* p_character)
{
    // displays a message that the entity has entered this state
}

template<class Entity_type>
void Idle_state<Entity_type>::evaluate(Entity_type* p_character)
{
    // entity performs a action that is not an attack depending on his needs
}

template<class Entity_type>
void Idle_state<Entity_type>::exit(Entity_type* p_character)
{
    // displays a message that the entity has exited this state
}

template<class Entity_type>
void Aggressive_state<Entity_type>::enter(Entity_type* p_character)
{
    // displays a message that the entity has entered this state
}

template<class Entity_type>
void Aggressive_state<Entity_type>::evaluate(Entity_type* p_character)
{
    // entity performs an attack
}

template<class Entity_type>
void Aggressive_state<Entity_type>::exit(Entity_type* p_character)
{
    // displays a message that the entity has exited this state
}

template<class Entity_type>
void Defensive_state<Entity_type>::enter(Entity_type* p_character)
{
    // displays a message that the entity has entered this state
}

template<class Entity_type>
void Defensive_state<Entity_type>::evaluate(Entity_type* p_character)
{
    // will begin to retreat and return fire
}

template<class Entity_type>
void Defensive_state<Entity_type>::exit(Entity_type* p_character)
{
    // displays a message that the entity has exited this state
}

template<class Entity_type>
void Run_state<Entity_type>::enter(Entity_type* p_character)
{
    // displays a message that the entity has entered this state
}

template<class Entity_type>
void Run_state<Entity_type>::evaluate(Entity_type* p_character)
{
    // entity will only attempt to flee
}

template<class Entity_type>
void Run_state<Entity_type>::exit(Entity_type* p_character)
{
    // displays a message that the entity has exited this state
}

template<class Entity_type>
void Desparate_state<Entity_type>::enter(Entity_type* p_character)
{
    // displays a message that the entity has entered this state
}

template<class Entity_type>
void Desparate_state<Entity_type>::evaluate(Entity_type* p_character)
{
    // will charge at opponent and attack them
}

template<class Entity_type>
void Desparate_state<Entity_type>::exit(Entity_type* p_character)
{
    // displays a message that the entity has exited this state
}