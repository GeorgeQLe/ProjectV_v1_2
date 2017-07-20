/*  Copyright 2017 George Le
    Definition of the member functions of the Attacks class
*/
#include "Attacks/Attacks.h"

Attacks::Attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable)
    : m_name(name), m_stats(damage, ammo_usage, base_attack_speed, usable)
{
    
}

Attacks::~Attacks()
{
    // Empty Destructor
}