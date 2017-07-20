/*  Copyright 2017 George Le
    Definition of member functions of the Ultimate_attacks class
*/
#include "Attacks/Ultimate_attacks.h"

Ultimate_attacks::Ultimate_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready) 
    : Attacks(name, damage, ammo_usage, base_attack_speed, ready)
{
    // Empty constructor except for the initializer list
}

Ultimate_attacks::~Ultimate_attacks()
{
    // Empty destructor
}

Default_ult_attack::Default_ult_attack() : Ultimate_attacks("Default_ult_attack", 0, 0, 0, false)
{
    // Empty constructor except for the initializer list
}

Default_ult_attack::Default_ult_attack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready)
    : Ultimate_attacks(name, damage, ammo_usage, base_attack_speed, ready)
{
    // Empty constructor except for the initializer list
}

Default_ult_attack::~Default_ult_attack()
{
    // Empty destructor
}

void Default_ult_attack::special_effect()
{
    // No special effects for default ultimate attack
}