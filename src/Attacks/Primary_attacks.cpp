/*  Copyright 2017 George Le
    Definition of the constructor and destructor of the Primary_attacks class
*/
#include "Attacks/Primary_attacks.h"

CPrimaryAttacks::CPrimaryAttacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable) 
    : CAttacks(name, damage, ammo_usage, base_attack_speed, usable)
{
    // Empty constructor except for the initializer list
}

CPrimaryAttacks::~CPrimaryAttacks()
{
    // Empty destructor
}