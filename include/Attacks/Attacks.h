/*  Copyright 2017 George Le
    Declaration of the Attacks class and its member functions
*/
#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>

#include "Attacks/Attack_stats.h"

class Attacks
{
    public:
    Attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable);
    virtual ~Attacks();
    
    // accessor functions
    std::string name() const { return m_name; };
    int damage() const { return m_stats.m_damage; }
    int ammo_usage() const { return m_stats.m_ammo_usage; }
    int base_attack_speed() const { return m_stats.m_base_attack_speed; }
    bool usable() const { return m_stats.m_usable; }
    
    // mutator functions
    
    // update functions for primary_attacks
    // this function updates damage for primary_attacks
    void update_damage(int weapon_damage_stat) { m_stats.m_damage = weapon_damage_stat; }
    // this function updates the amount of ammo a weapon uses
    void update_ammo_usage(int weapon_ammo_count) { m_stats.m_ammo_usage = weapon_ammo_count; }
    // this function updates the speed of the attack
    void update_base_attack_speed(int weapon_attack_speed) { m_stats.m_base_attack_speed = weapon_attack_speed; }
    
    private:
    std::string m_name; // name of attack
    Attack_stats m_stats;
};

#endif