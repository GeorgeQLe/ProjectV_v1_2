/*  Copyright 2017 George Le
    
    Implements a basic game AI as a finite state machine. Designed using the state design pattern.
    Completely generic with the use of templates
    
    Declaration:
        Class:
            -State_machine
*/
#ifndef BASIC_STATE_AI_H
#define BASIC_STATE_AI_H

#include <memory>

template<class Entity_type>
class State_machine
{
    public:
    State_machine(Entity_type* owner): mp_owner(owner), mp_current_state(nullptr), mp_previous_state(nullptr), mp_global_state(nullptr) {} 

    // mutator functions to set a state machine
    void set_current_state(std::shared_ptr<Base_state<Entity_type>> state) { mp_current_state = state; }
    void set_previous_state(std::shared_ptr<Base_state<Entity_type>> state) { mp_previous_state = state; }
    void set_global_state(std::shared_ptr<Base_state<Entity_type>> state) { mp_previous_state = state; }
    
    // accessor functions
    std::shared_ptr<Base_state<Entity_type>> current_state() const { return mp_current_state; }
    std::shared_ptr<Base_state<Entity_type>> previous_state() const { return mp_previous_state; }
    std::shared_ptr<Base_state<Entity_type>> global_state() const { return mp_global_state; }
    
    // evaluates the global and current state
    bool update();
    // change to a new state
    void change_state(std::shared_ptr<Base_state<Entity_type>> p_new_state);
    // change to previous state
    void change_to_previous_state() { change_state(mp_previous_state); }
    
    private:
    // a pointer to the owner of this state machine
    Entity_type* mp_owner;
    
    // stores what the current state is
    std::shared_ptr<Base_state<Entity_type>> mp_current_state;
    // stores what the previous state is
    std::shared_ptr<Base_state<Entity_type>> mp_previous_state;
    // this state is called for every update
    std::shared_ptr<Base_state<Entity_type>> mp_global_state;
};

#include "State_machine.imp"

#endif