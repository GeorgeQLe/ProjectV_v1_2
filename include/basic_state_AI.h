/*  Copyright 2017 George Le
    
    Implements a basic game AI as a finite state machine. Designed using the state design pattern.
    Completely generic
*/
#ifndef BASIC_STATE_AT_H
#define BASIC_STATE_AT_H

// base state class to be used with base hostile class
// templated to make it generic
template<class Entity_type>
class Base_state
{
    public:
    // displays a little message to let player know the observable state of hostiles
    virtual void enter(Entity_type*) = 0;
    // actually executes the control of the hostile's actions
    virtual void evaluate(Entity_type*) = 0;
    // displays a little message to let player know the change in state of hostiles
    virtual void exit(Entity_type*) = 0;
    virtual ~Base_state() {}
};

template<class Entity_type>
class Idle_state : public Base_state<Entity_type>
{
    public:
    void enter(Entity_type* p_character);
    void evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Aggressive_state : public Base_state<Entity_type>
{
    public:
    void enter(Entity_type* p_character);
    void evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Defensive_state : public Base_state<Entity_type>
{
    public:
    void enter(Entity_type* p_character);
    void evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Run_state : public Base_state<Entity_type>
{
    public:
    void enter(Entity_type* p_character);
    void evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Desparate_state : public Base_state<Entity_type>
{
    public:
    void enter(Entity_type* p_character);
    void evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class State_machine
{
    public:
    State_machine(Entity_type* owner): mp_owner(owner), mp_currecnt_state(nullptr), mp_previous_state(nullptr), mp_global_state(nullptr) {} 

    // mutator functions to set a state machine
    void set_current_state(Base_state<Entity_type>* state) { mp_currecnt_state = state; }
    void set_previous_state(Base_state<Entity_type>* state) { mp_previous_state = state; }
    void set_global_state(Base_state<Entity_type>* state) { mp_previous_state = state; }
    // accessor functions
    Base_state<Entity_type>* current_state() const { return mp_currecnt_state; }
    Base_state<Entity_type>* previous_state() const { return mp_previous_state; }
    Base_state<Entity_type>* global_state() const { return mp_global_state; }
    
    // evaluates the global and current state
    void update() const;
    // change to a new state
    void change_state(Base_state<Entity_type>* p_new_state);
    // 
    void revert_previous_state() { change_state(mp_previous_state); }
    
    private:
    // a pointer to the owner of this state machine
    Entity_type* mp_owner;
    
    // stores what the current state is
    Base_state<Entity_type>* mp_currecnt_state;
    
    // stores what the previous state is
    Base_state<Entity_type>* mp_previous_state;
    
    // this state is called for every update
    Base_state<Entity_type>* mp_global_state;
};

#endif