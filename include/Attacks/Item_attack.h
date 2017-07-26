/*  Copyright 2017 George Le
    Declaration of the Item_attack class and its member functions
*/
#ifndef ITEM_ATTACK_H
#define ITEM_ATTACK_H

#include "Attacks/Attacks.h"

class CItemAttack: public CAttacks
{
    public:
    CItemAttack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable);
    virtual ~CItemAttack();
    
    // Similar to ultimate attacks, usually much weaker
    // TO BE DESIGNED
    //bool Operator() {}
    //virtual void Effect() = 0;
};

#endif