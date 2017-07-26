/*  Copyright 2017 George Le
    Definition of the member functions of the Item_attack class
*/
#include "Attacks/Item_attack.h"

CItemAttack::CItemAttack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable)
    : CAttacks(name, damage, ammo_usage, base_attack_speed, usable)
{
    // Empty constructor except for the initializer list
}

CItemAttack::~CItemAttack()
{
    // Empty destructor
}