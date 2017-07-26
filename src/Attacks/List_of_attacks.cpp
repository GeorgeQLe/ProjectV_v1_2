/*  Copyright 2017 George Le
    Definitions of member functions of the SListOfAttacks struct
*/
#include <iostream>
#include "Attacks/List_of_attacks.h"

SListOfAttacks::SListOfAttacks() 
        : m_primary_attack(new CPrimaryAttacks("Shoot", 0, 0, 0, true)), pm_ult(new CDefaultUltAttack()),
                                    pm_use_offensive_item(new CItemAttack("Potion", 0, 0, 0, false))
{
    // adds the names of the various attacks to the vector
    m_list_of_attack_names.push_back(m_primary_attack->name());
    m_list_of_attack_names.push_back(pm_ult->name());
    m_list_of_attack_names.push_back(pm_use_offensive_item->name());
    
    // by default set all the attacks to true
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
}

SListOfAttacks::SListOfAttacks(std::vector<std::string> list_of_attack_names) 
    : m_primary_attack(new CPrimaryAttacks(list_of_attack_names.at(0), 0, 0, 0, true)), pm_ult(new CDefaultUltAttack(list_of_attack_names.at(1), 0, 0, 0, false)),
    pm_use_offensive_item(new CItemAttack(list_of_attack_names.at(2), 0, 0, 0, false)), m_list_of_attack_names(list_of_attack_names)
{
    // by default set primary_attacks to true, the others to false
    // primary_attack
    m_possible_attacks.push_back(true);
    // ultimate_attack
    m_possible_attacks.push_back(false);
    // offensive items
    m_possible_attacks.push_back(false);
}

void SListOfAttacks::ListAttacks()
{
    int f_counter = 1;
    for(auto it = m_list_of_attack_names.begin(); it != m_list_of_attack_names.end(); it++)
    {
        std::cout << f_counter << "." << *it << std::endl;
        ++f_counter;
    }
}