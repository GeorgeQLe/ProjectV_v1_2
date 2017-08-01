/*  Copyright 2017 George Le
    
    Implements a basic game AI as a finite state machine. Designed using the state design pattern.
    Completely generic with the use of templates
    
    Declaration:
        Class:
            -CStateMachine
*/
#ifndef BASIC_STATE_AI_H
#define BASIC_STATE_AI_H

#include <memory>

#include "AI/Base_state.h"

template<class TEntityType>
class CStateMachine
{
    public:
    CStateMachine(TEntityType* owner): mp_owner(owner), mp_current_state(nullptr), mp_previous_state(nullptr), mp_global_state(nullptr) {} 

    // mutator functions to set a state machine
    void SetCurrentState(std::shared_ptr<CBaseState<TEntityType>> state) { mp_current_state = state; }
    void SetPreviousState(std::shared_ptr<CBaseState<TEntityType>> state) { mp_previous_state = state; }
    void SetGlobalState(std::shared_ptr<CBaseState<TEntityType>> state) { mp_previous_state = state; }
    
    // accessor functions
    std::shared_ptr<CBaseState<TEntityType>> CurrentState() const { return mp_current_state; }
    std::shared_ptr<CBaseState<TEntityType>> PreviousState() const { return mp_previous_state; }
    std::shared_ptr<CBaseState<TEntityType>> GlobalState() const { return mp_global_state; }
    
    // evaluates the global and current state
    bool Update();
    // change to a new state
    void ChangeState(std::shared_ptr<CBaseState<TEntityType>> p_new_state);
    // change to previous state
    void ChangeToPreviousState() { ChangeState(mp_previous_state); }
    
    private:
    // a pointer to the owner of this state machine
    TEntityType* mp_owner;
    
    // stores what the current state is
    std::shared_ptr<CBaseState<TEntityType>> mp_current_state;
    // stores what the previous state is
    std::shared_ptr<CBaseState<TEntityType>> mp_previous_state;
    // this state is called for every update
    std::shared_ptr<CBaseState<TEntityType>> mp_global_state;
};

#include "State_machine.imp"

#endif