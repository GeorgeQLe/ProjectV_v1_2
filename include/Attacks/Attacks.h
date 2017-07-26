/*  Copyright 2017 George Le
    Declaration of the Attacks class and its member functions
*/
#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>

#include "Attacks/Attack_stats.h"

class CAttacks
{
    public:
    CAttacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable);
    virtual ~CAttacks();
    
    // accessor functions
    std::string name() const { return m_name; };
    int Damage() const { return m_stats.m_damage; }
    int AmmoUsage() const { return m_stats.m_ammo_usage; }
    int BaseAttackSpeed() const { return m_stats.m_base_attack_speed; }
    bool Usable() const { return m_stats.m_usable; }
    
    // mutator functions
    
    // update functions for primary_attacks
    // this function updates damage for primary_attacks
    void UpdateDamage(int weapon_damage_stat) { m_stats.m_damage = weapon_damage_stat; }
    // this function updates the amount of ammo a weapon uses
    void UpdateAmmoUsage(int weapon_ammo_count) { m_stats.m_ammo_usage = weapon_ammo_count; }
    // this function updates the speed of the attack
    void UpdateBaseAttackSpeed(int weapon_attack_speed) { m_stats.m_base_attack_speed = weapon_attack_speed; }
    
    private:
    // name of attack
    std::string m_name;
    CAttackStats m_stats;
};

#endif //ATTACKS_H