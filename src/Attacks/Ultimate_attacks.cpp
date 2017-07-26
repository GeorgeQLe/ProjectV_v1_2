/*  Copyright 2017 George Le
    Definition of member functions of the Ultimate_attacks class
*/
#include "Attacks/Ultimate_attacks.h"

CUltimateAttacks::CUltimateAttacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready) 
    : CAttacks(name, damage, ammo_usage, base_attack_speed, ready)
{
    // Empty constructor except for the initializer list
}

CUltimateAttacks::~CUltimateAttacks()
{
    // Empty destructor
}

CDefaultUltAttack::CDefaultUltAttack() : CUltimateAttacks("Default_ult_attack", 0, 0, 0, false)
{
    // Empty constructor except for the initializer list
}

CDefaultUltAttack::CDefaultUltAttack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready)
    : CUltimateAttacks(name, damage, ammo_usage, base_attack_speed, ready)
{
    // Empty constructor except for the initializer list
}

CDefaultUltAttack::~CDefaultUltAttack()
{
    // Empty destructor
}

void CDefaultUltAttack::SpecialEffect()
{
    // No special effects for default ultimate attack
}