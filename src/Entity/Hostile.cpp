/*	Copyright 2016 George Le
    Definition of functions declared in hostile.h
*/
#include <iostream>
#include "AI/Entity_states.h"
#include "Entity/Hostile.h"

Hostile::Hostile() : Combat_entity("Dummy", 1, 1, 1, true, 0, 0, 0, 0, 0, 1, 10, 10, 0, 1), 
            mp_AI_system(new State_machine<Hostile>(this)), m_can_flee(false), m_experience_points_granted(100)
{
    m_target.lock() = nullptr;
    
    mp_AI_system->set_current_state(Idle_state<Hostile>::get_instance());
    
    mp_AI_system->set_global_state(Global_state<Hostile>::get_instance());
}

Hostile::Hostile(int difficulty) : 
        Combat_entity("Dummy", 1, 1, 1, true, difficulty, difficulty, difficulty, difficulty, difficulty, 1, 10, 10, 0, 1), 
        mp_AI_system(new State_machine<Hostile>(this)), m_can_flee(false), m_experience_points_granted(100)
{
    m_target.lock() = nullptr;
    
    mp_AI_system->set_current_state(Idle_state<Hostile>::get_instance());
    
    mp_AI_system->set_global_state(Global_state<Hostile>::get_instance());
}

Hostile::~Hostile()
{
    // Empty destructor
}

void Hostile::print_header_stats()
{
    std::cout << "Hostile name: " << name() << " Level: " << level() << std::endl;
    std::cout << "Health: " << current_health_total() << "/" << total_health() << std::endl;
}

bool Hostile::turn(std::vector<std::shared_ptr<Combat_entity>>& turn_order)
{
    bool f_success = true;
    // if hostile is still alive then call the update function
    if(this->current_health_total() > 0)
    {
        f_success = update();
    }
    // else the hostile is dead and fails to take its turn
    else if (this->current_health_total() == 0)
    {
        std::cout << "Hostile is dead!" << std::endl;
        f_success = false;
    }
    
    // return the result of the hostile's turn
    return f_success;
}

bool Hostile::update()
{
    // if the current health total lower or equal to half of the health of
    // the hostile then switch the hostile to a defensive state where the 
    // hostile retreats and takes unaimed shots
    if(this->current_health_total() <= (this->total_health() / 2))
    {
        std::cout << "Enter defensive_state" << std::endl;
        mp_AI_system->change_state(Defensive_state<Hostile>::get_instance());
    }
    // if the current health total lower or equal to a quarter of the health
    // of the hostile then switch the hostile to a run state where the hostile
    // attempts to flee
    else if(this->current_health_total() <= (this->total_health() / 4))
    {
        mp_AI_system->change_state(Run_state<Hostile>::get_instance());
    }
    // if the current health total lower to equal to a tenth of the health
    // of the hostile then switch the hostile to a desparate state where the
    // hostile charges at its target and attack it
    else if(this->current_health_total() <= (this->total_health() / 10))
    {
        mp_AI_system->change_state(Desperate_state<Hostile>::get_instance());
    }
    // if the hostile doesn't have a target to shoot at then go to an idle state
    else if(m_target.lock() == nullptr)
    {
        std::cout << "Change to idle state" << std::endl;
        mp_AI_system->change_state(Idle_state<Hostile>::get_instance());
    }
    // if none of those conditions exist then the hostile will try his best to
    // kill his target
    else if(m_target.lock() != nullptr)
    {
        mp_AI_system->change_state(Aggressive_state<Hostile>::get_instance());
    }
    
    if(this->current_health_total() > 0)
    {
        // uses a finite-state machine to serve as the hostile's AI, calls this 
        // function to update the current state if needed then execute the current 
        // state
        std::cout << "Update" << std::endl;
        return mp_AI_system->update();
    }
    
    return false;
}

bool Hostile::attack()
{
    return m_target.lock()->damage_entity(m_hostile_attacks.m_primary_attack.damage());
}

bool Hostile::move()
{
    bool f_success = false;
    
    // move
    
    
    return f_success;
}

bool Hostile::flee()
{
    std::cout << name() << " tries to flee";
    
    if(m_can_flee == false)
    {
        m_can_flee = true;
    }
    else if(m_can_flee)
    {
        
    }
    
    return m_can_flee;
}

void Hostile::get_target(std::vector<std::shared_ptr<Combat_entity>> list_of_targets)
{
    
}

void add_hostile(std::vector<std::shared_ptr<Hostile>>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int)
{
    for(int i = 0; i < number_of_hostiles; i++)
    {
        // generates random hostile and inserts it into the list of hostiles
        std::shared_ptr<Hostile> fp_hostile(new Hostile(enum_difficult_converted_to_int));
        list_of_hostiles.push_back(fp_hostile);
    }
}