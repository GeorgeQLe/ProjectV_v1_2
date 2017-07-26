#ifndef PRIMARY_ATTACKS_H
#define PRIMARY_ATTACKS_H

#include "Attacks/Attacks.h"

class CPrimaryAttacks: public CAttacks
{
    public:
    CPrimaryAttacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable);
    ~CPrimaryAttacks();
    
    virtual bool SpecialEffect() { return false; }
};

#endif