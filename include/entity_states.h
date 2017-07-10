/*  Copyright 2017 George Le

    Declarations:
*/
#ifndef ENTITY_STATES_H
#define ENTITY_STATES_H
#include "basic_state_AI.h"

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

#include "entity_states.imp"

#endif