/*  Copyright 2017 George Le
    Declaration of the Attack_stats struct and its data members
*/
#ifndef ATTACK_STATS_H
#define ATTACK_STATS_H

struct CAttackStats
{
    public:
    CAttackStats(int damage, int ammo_usage, int base_attack_speed, bool available);
    
    int m_damage; // damage is an int to interact with current health total
    int m_ammo_usage; // amount of weapon capacity the attack uses up
    int m_base_attack_speed; // speed of attack without character modifier
    bool m_usable; // is the attack available or disabled
};

#endif