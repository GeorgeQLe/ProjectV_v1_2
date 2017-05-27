/*  Copyright 2017 George Le
    
*/
#include "attacks.h"

void Attacks::update(Stat to_be_changed, int new_stat_amount)
{
    switch(to_be_changed)
    {
        case 1:
        m_stats.m_damage = new_stat_amount;
        break;
        case 2:
        m_stats.m_ammo_usage = new_stat_amount;
        break;
        case 3:
        m_stats.m_base_attack_speed = new_stat_amount;
        break;
        default:
        break;
    }
}

int Attacks::get_stat(Stat to_be_returned)
{
    int return_amount = 0;
    switch(to_be_returned)
    {
        case 1:
        return_amount = m_stats.m_damage;
        break;
        case 2:
        return_amount = m_stats.m_ammo_usage;
        break;
        case 3:
        return_amount = m_stats.m_base_attack_speed;
        break;
        default:
        break;
    }
    return return_amount;
}

List_of_attacks::List_of_attacks() : m_primary_attack("Shoot", 0, 0, 0, true)
{
    pm_ult = new Ultimate_attacks("Spray and pay", 0, 0, 0, false);
    pm_use_offensive_item = new Item_attack("Potion", 0, 0, 0, false);
    
    // adds the names of the various attacks to the vector
    m_list_of_attack_names.push_back(m_primary_attack.get_name());
    m_list_of_attack_names.push_back(pm_ult->get_name());
    m_list_of_attack_names.push_back(pm_use_offensive_item->get_name());
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
}

List_of_attacks::List_of_attacks(std::vector<std::string> list_of_attack_names) 
    : m_primary_attack(list_of_attack_names.at(0), 0, 0, 0, true), m_list_of_attack_names(list_of_attack_names)
{
    pm_ult = new Ultimate_attacks(list_of_attack_names.at(1), 0, 0, 0, false);
    pm_use_offensive_item = new Item_attack(list_of_attack_names.at(2), 0, 0, 0, false);
    
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
}