/*	Copyright 2016 George Le
    Definition of functions declared in hostile.h
*/
#include <iostream>
#include "AI/Entity_states.h"
#include "Entity/Hostile.h"

CHostile::CHostile() : CCombatEntity("Dummy", 1, 1, 1, true, 0, 0, 0, 0, 0, 1, 10, 10, 0, 1), 
            mp_AI_system(new CStateMachine<CHostile>(this)), m_can_flee(false), m_experience_points_granted(100)
{
    m_target.lock() = nullptr;
    
    mp_AI_system->SetCurrentState(CIdleState<CHostile>::GetInstance());
    
    mp_AI_system->SetGlobalState(CGlobalState<CHostile>::GetInstance());
}

CHostile::CHostile(int difficulty) : 
        CCombatEntity("Dummy", 1, 1, 1, true, difficulty, difficulty, difficulty, difficulty, difficulty, 1, 10, 10, 0, 1), 
        mp_AI_system(new CStateMachine<CHostile>(this)), m_can_flee(false), m_experience_points_granted(100)
{
    m_target.lock() = nullptr;
    
    mp_AI_system->SetCurrentState(CIdleState<CHostile>::GetInstance());
    
    mp_AI_system->SetGlobalState(CGlobalState<CHostile>::GetInstance());
}

CHostile::~CHostile()
{
    // Empty destructor
}

void CHostile::PrintHeaderStats()
{
    std::cout << "Hostile name: " << Name() << " Level: " << Level() << std::endl;
    std::cout << "Health: " << CurrentHealthTotal() << "/" << TotalHealth() << std::endl;
}

bool CHostile::Turn(std::vector<std::shared_ptr<CCombatEntity>>& turn_order)
{
    bool f_success = true;
    // if hostile is still alive then call the Update function
    if(this->CurrentHealthTotal() > 0)
    {
        f_success = Update(turn_order);
    }
    // else the hostile is dead and fails to take its turn
    else if (this->CurrentHealthTotal() == 0)
    {
        std::cout << "Hostile is dead!" << std::endl;
        f_success = false;
    }
    
    // return the result of the hostile's turn
    return f_success;
}

bool CHostile::Update(std::vector<std::shared_ptr<CCombatEntity>> list_of_targets)
{
    // if the current health total lower or equal to half of the health of
    // the hostile then switch the hostile to a defensive state where the 
    // hostile retreats and takes unaimed shots
    if(this->CurrentHealthTotal() <= (this->TotalHealth() / 2))
    {
        std::cout << "Enter defensive_state" << std::endl;
        mp_AI_system->ChangeState(CDefensiveState<CHostile>::GetInstance());
    }
    // if the current health total lower or equal to a quarter of the health
    // of the hostile then switch the hostile to a run state where the hostile
    // attempts to flee
    else if(this->CurrentHealthTotal() <= (this->TotalHealth() / 4))
    {
        mp_AI_system->ChangeState(CRunState<CHostile>::GetInstance());
    }
    // if the current health total lower to equal to a tenth of the health
    // of the hostile then switch the hostile to a desparate state where the
    // hostile charges at its target and attack it
    else if(this->CurrentHealthTotal() <= (this->TotalHealth() / 10))
    {
        mp_AI_system->ChangeState(CDesperateState<CHostile>::GetInstance());
    }
    // if the hostile doesn't have a target to shoot at then 
    else if(m_target.lock() == nullptr)
    {
        // try to find a new target
        if(GetTarget(list_of_targets))
        {
            std::cout << "Found new target" << std::endl;
        }
        // else go to an idle state
        else
        {
            std::cout << "Change to idle state" << std::endl;
            mp_AI_system->ChangeState(CIdleState<CHostile>::GetInstance());
        }
    }
    // if none of those conditions exist then the hostile will try his best to
    // kill his target
    else if(m_target.lock() != nullptr)
    {
        mp_AI_system->ChangeState(CAggressiveState<CHostile>::GetInstance());
    }
    
    if(this->CurrentHealthTotal() > 0)
    {
        // uses a finite-state machine to serve as the hostile's AI, calls this 
        // function to Update the current state if needed then execute the current 
        // state
        std::cout << "Update" << std::endl;
        return mp_AI_system->Update();
    }
    
    return false;
}

bool CHostile::Attack()
{
    return m_target.lock()->DamageEntity(m_hostile_attacks.m_primary_attack->Damage());
}

bool CHostile::Move()
{
    bool f_success = false;
    
    // move
    
    
    return f_success;
}

bool CHostile::Flee()
{
    std::cout << Name() << " tries to flee";
    
    if(m_can_flee == false)
    {
        m_can_flee = true;
    }
    else if(m_can_flee)
    {
        
    }
    
    return m_can_flee;
}

bool CHostile::GetTarget(std::vector<std::shared_ptr<CCombatEntity>> list_of_targets)
{
    bool f_success = false;
    
    return f_success;
}

void add_hostile(std::vector<std::shared_ptr<CHostile>>& list_of_hostiles, int number_of_hostiles, int enum_difficult_converted_to_int)
{
    for(int i = 0; i < number_of_hostiles; i++)
    {
        // generates random hostile and inserts it into the list of hostiles
        std::shared_ptr<CHostile> fp_hostile(new CHostile(enum_difficult_converted_to_int));
        list_of_hostiles.push_back(fp_hostile);
    }
}