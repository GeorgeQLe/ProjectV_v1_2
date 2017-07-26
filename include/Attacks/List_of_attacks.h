/*  Copyright 2017 George Le
    Declaration of the List_of_attacks struct and its member function
*/
#ifndef LIST_OF_ATTACKS_H
#define LIST_OF_ATTACKS_H

#include <string>
#include <vector>
#include <memory>

#include "Attacks/Primary_attacks.h"
#include "Attacks/Ultimate_attacks.h"
#include "Attacks/Item_attack.h"

enum Stat { DAMAGE = 1, AMMO, SPEED};
enum Type_of_attack { NO_ATTACK = 0, ATTACK = 1, ULTIMATE = 2, ITEM = 3};

struct SListOfAttacks
{
    SListOfAttacks();
    // Constructor that is the same as the default constructor except 
    // that the user can pass in a predefined vector to set up the list of
    // attack names, index 0 for primary attacks, 1 for ult, and 2 for item.
    // Also assigns those names to the attacks themselves.
    SListOfAttacks(std::vector<std::string> list_of_attack_names);
    // TO BE DESIGNED
    //SListOfAttacks(Attacks* primary_attack, Attacks* ultimate_attack, Attacks* item_attack);
    ~SListOfAttacks() {}
    
    // lists out the name of the three possible attack options
    void ListAttacks();
    
    // update functions for primary_attacks
    // this function updates damage for primary_attacks
    void UpdateDamage(int strength_stat, int weapon_damage_stat) { m_primary_attack->UpdateDamage(weapon_damage_stat + strength_stat); }
    // this function updates the amount of ammo a weapon uses
    void UpdateAmmoUsage(int weapon_ammo_count) { m_primary_attack->UpdateAmmoUsage(weapon_ammo_count); }
    // this function updates the speed of the attack
    void UpdateBaseAttackSpeed(int weapon_attack_speed) { m_primary_attack->UpdateBaseAttackSpeed(weapon_attack_speed); }
    
    // The three classes that make up the struct
    // pointer to Primary attacks, Ultimate attacks, and Item attacks to 
    // allow for polymorphism 
    std::shared_ptr<CPrimaryAttacks> m_primary_attack;
    std::shared_ptr<CUltimateAttacks> pm_ult;
    std::shared_ptr<CItemAttack> pm_use_offensive_item;
    // convienent collection of attack names
    // Primary Attack is index 0 by default
    // Ultimate Attack is index 1
    // Items is index 2
    std::vector<std::string> m_list_of_attack_names;
    std::vector<bool> m_possible_attacks;
};

#endif // LIST_OF_ATTACKS_H