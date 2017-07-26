/*  Copyright 2017 George Le
    Definition of the constructor of the Attack_stats struct
*/
#include "Attacks/Attack_stats.h"

CAttackStats::CAttackStats(int damage, int ammo_usage, int base_attack_speed, bool available)
    : m_damage(damage), m_ammo_usage(ammo_usage), m_base_attack_speed(base_attack_speed), m_usable(available)
{
    // Empty constructor except for the initializer list    
}