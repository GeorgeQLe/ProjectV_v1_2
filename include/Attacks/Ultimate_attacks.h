/*  Copyright 2017 George Le
    Declaration of the Ultimate_attacks class and its member functions
*/
#ifndef ULTIMATE_ATTACKS_H
#define ULTIMATE_ATTACKS_H

#include "Attacks/Attacks.h"

class CUltimateAttacks: public CAttacks
{
    public:
    CUltimateAttacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready);
    virtual ~CUltimateAttacks();
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    virtual void SpecialEffect() = 0;
};

class CDefaultUltAttack: public CUltimateAttacks
{
    public:
    CDefaultUltAttack();
    CDefaultUltAttack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready);
    ~CDefaultUltAttack();

    virtual void SpecialEffect();
};

#endif