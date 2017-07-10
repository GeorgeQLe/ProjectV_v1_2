/*  Copyright 2017 George Le
    
    Defines functions declared in basic_hostile_AI.h
*/
#include <assert.h>
#include "basic_state_AI.h"

template<class Entity_type>
void State_machine<Entity_type>::update()
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