/*  Copyright 2017 George Le

    Declarations:
*/
#ifndef ENTITY_STATES_H
#define ENTITY_STATES_H

#include <memory>
#include "basic_state_AI.h"

template<class Entity_type>
class Global_state : public Base_state<Entity_type>
{
    public:
    static std::shared_ptr<Global_state> get_instance()
    {
        static std::shared_ptr<Global_state> instance(new Global_state<Entity_type>);
        return instance;
    }
    
    void enter(Entity_type* p_character) {}
    bool evaluate(Entity_type* p_character) { return true; }
    void exit(Entity_type* p_character) {}
};

template<class Entity_type>
class Idle_state : public Base_state<Entity_type>
{
    private:
    Idle_state() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<Idle_state> get_instance()
    {
        static std::shared_ptr<Idle_state> instance(new Idle_state<Entity_type>);
        return instance;
    }
    
    void enter(Entity_type* p_character);
    bool evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Aggressive_state : public Base_state<Entity_type>
{
    private:
    Aggressive_state() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<Aggressive_state> get_instance()
    {
        static std::shared_ptr<Aggressive_state> instance(new Aggressive_state<Entity_type>);
        return instance;
    }
    
    void enter(Entity_type* p_character);
    bool evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Defensive_state : public Base_state<Entity_type>
{
    private:
    Defensive_state() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<Defensive_state> get_instance()
    {
        static std::shared_ptr<Defensive_state> instance(new Defensive_state<Entity_type>);
        return instance;
    }
    
    void enter(Entity_type* p_character);
    bool evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Run_state : public Base_state<Entity_type>
{
    private:
    Run_state() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<Run_state> get_instance()
    {
        static std::shared_ptr<Run_state> instance(new Run_state<Entity_type>);
        return instance;
    }
    
    void enter(Entity_type* p_character);
    bool evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

template<class Entity_type>
class Desperate_state : public Base_state<Entity_type>
{
    private:
    Desperate_state() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<Desperate_state> get_instance()
    {
        static std::shared_ptr<Desperate_state> instance((new Desperate_state<Entity_type>));
        return instance;
    }
    
    void enter(Entity_type* p_character);
    bool evaluate(Entity_type* p_character);
    void exit(Entity_type* p_character);
};

#include "entity_states.imp"

#endif