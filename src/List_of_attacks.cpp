/*  Copyright 2017 George Le
    Definitions of functions declared in attacks.h
*/
#include <iostream>
#include "List_of_attacks.h"

List_of_attacks::List_of_attacks() : m_primary_attack("Shoot", 0, 0, 0, true), pm_ult(new Ultimate_attacks("Spray and pay", 0, 0, 0, false)),
                                    pm_use_offensive_item(new Item_attack("Potion", 0, 0, 0, false))
{
    // adds the names of the various attacks to the vector
    m_list_of_attack_names.push_back(m_primary_attack.get_name());
    m_list_of_attack_names.push_back(pm_ult->get_name());
    m_list_of_attack_names.push_back(pm_use_offensive_item->get_name());
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
}

List_of_attacks::List_of_attacks(std::vector<std::string> list_of_attack_names) 
    : m_primary_attack(list_of_attack_names.at(0), 0, 0, 0, true), pm_ult(new Ultimate_attacks(list_of_attack_names.at(1), 0, 0, 0, false)),
    pm_use_offensive_item(new Item_attack(list_of_attack_names.at(2), 0, 0, 0, false)), m_list_of_attack_names(list_of_attack_names)
{
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
    m_possible_attacks.push_back(true);
}

void List_of_attacks::list_attacks()
{
    int counter = 1;
    for(auto it = m_list_of_attack_names.begin(); it != m_list_of_attack_names.end(); it++)
    {
        std::cout << counter << "." << *it << std::endl;
        ++counter;
    }
}