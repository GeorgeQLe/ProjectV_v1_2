/*  Copyright 2017 George Le

    Declarations:
*/
#ifndef ENTITY_STATES_H
#define ENTITY_STATES_H

#include <memory>
#include "Base_state.h"

template<class TEntityType>
class CGlobalState : public CBaseState<TEntityType>
{
    public:
    static std::shared_ptr<CGlobalState> GetInstance()
    {
        static std::shared_ptr<CGlobalState> instance(new CGlobalState<TEntityType>);
        return instance;
    }
    
    void Enter(TEntityType* p_character) {}
    bool Evaluate(TEntityType* p_character) { return true; }
    void Exit(TEntityType* p_character) {}
};

template<class TEntityType>
class CIdleState : public CBaseState<TEntityType>
{
    private:
    CIdleState() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<CIdleState> GetInstance()
    {
        static std::shared_ptr<CIdleState> instance(new CIdleState<TEntityType>);
        return instance;
    }
    
    void Enter(TEntityType* p_character);
    bool Evaluate(TEntityType* p_character);
    void Exit(TEntityType* p_character);
};

template<class TEntityType>
class CAggressiveState : public CBaseState<TEntityType>
{
    private:
    CAggressiveState() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<CAggressiveState> GetInstance()
    {
        static std::shared_ptr<CAggressiveState> instance(new CAggressiveState<TEntityType>);
        return instance;
    }
    
    void Enter(TEntityType* p_character);
    bool Evaluate(TEntityType* p_character);
    void Exit(TEntityType* p_character);
};

template<class TEntityType>
class CDefensiveState : public CBaseState<TEntityType>
{
    private:
    CDefensiveState() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<CDefensiveState> GetInstance()
    {
        static std::shared_ptr<CDefensiveState> instance(new CDefensiveState<TEntityType>);
        return instance;
    }
    
    void Enter(TEntityType* p_character);
    bool Evaluate(TEntityType* p_character);
    void Exit(TEntityType* p_character);
};

template<class TEntityType>
class CRunState : public CBaseState<TEntityType>
{
    private:
    CRunState() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<CRunState> GetInstance()
    {
        static std::shared_ptr<CRunState> instance(new CRunState<TEntityType>);
        return instance;
    }
    
    void Enter(TEntityType* p_character);
    bool Evaluate(TEntityType* p_character);
    void Exit(TEntityType* p_character);
};

template<class TEntityType>
class CDesperateState : public CBaseState<TEntityType>
{
    private:
    CDesperateState() {}
    
    public:
    // This is a singleton
    static std::shared_ptr<CDesperateState> GetInstance()
    {
        static std::shared_ptr<CDesperateState> instance((new CDesperateState<TEntityType>));
        return instance;
    }
    
    void Enter(TEntityType* p_character);
    bool Evaluate(TEntityType* p_character);
    void Exit(TEntityType* p_character);
};

#include "Entity_states.imp"

#endif