/*  Copyright 2017 George Le
    Declaration of the Ultimate_attacks class and its member functions
*/
#ifndef ULTIMATE_ATTACKS_H
#define ULTIMATE_ATTACKS_H

#include "Attacks/Attacks.h"

class Ultimate_attacks: public Attacks
{
    public:
    Ultimate_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready);
    virtual ~Ultimate_attacks();
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    virtual void special_effect() = 0;
};

class Default_ult_attack: public Ultimate_attacks
{
    public:
    Default_ult_attack();
    Default_ult_attack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready);
    ~Default_ult_attack();

    virtual void special_effect();
};

#endif