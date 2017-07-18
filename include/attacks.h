/*  Copyright 2017 George Le
    
    Declaration:
        
*/
#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>
#include <vector>
#include <memory>

enum Stat { DAMAGE = 1, AMMO, SPEED};
enum Type_of_attack { NO_ATTACK = 0, ATTACK = 1, ULTIMATE = 2, ITEM = 3};

struct Attack_stats
{
    Attack_stats(int damage, int ammo_usage, int base_attack_speed, bool available)
    : m_damage(damage), m_ammo_usage(ammo_usage), m_base_attack_speed(base_attack_speed),
    m_usable(available) {}
    
    int m_damage; // damage is an int to interact with current health total
    int m_ammo_usage; // amount of weapon capacity the attack uses up
    int m_base_attack_speed; // speed of attack without character modifier
    bool m_usable; // is the attack available or disabled
};

class Attacks
{
    public:
    Attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable)
    : m_name(name), m_stats(damage, ammo_usage, base_attack_speed, usable) {}
    virtual ~Attacks() {}
    
    // accessor functions
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
    
    std::string get_name() const { return m_name; };
    
    private:
    std::string m_name; // name of attack
    Attack_stats m_stats;
};

class Primary_attacks: public Attacks
{
    public:
    Primary_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable) 
    : Attacks(name, damage, ammo_usage, base_attack_speed, usable) {}
    ~Primary_attacks() {}
};

class Ultimate_attacks: public Attacks
{
    public:
    Ultimate_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready) 
    : Attacks(name, damage, ammo_usage, base_attack_speed, ready) {}
    ~Ultimate_attacks() {}
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    virtual void special_effect() {}
};

// class Default_ult_attack: public Ultimate_attacks
// {
//     public:
//     Default_ult_attack() : Ultimate_attacks(0, 0, 0,) {}
    
//     virtual void special_effect();
// };

class Item_attack: public Attacks
{
    public:
    Item_attack(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable) 
    : Attacks(name, damage, ammo_usage, base_attack_speed, usable) {}
    ~Item_attack() {}
    
    // Similar to ultimate attacks, usually much weaker
    void effect() {}
};

struct List_of_attacks
{
    List_of_attacks();
    // Constructor that is the same as the default constructor except 
    // that the user can pass in a predefined vector to set up the list of
    // attack names, index 0 for primary attacks, 1 for ult, and 2 for item.
    // Also assigns those names to the attacks themselves.
    List_of_attacks(std::vector<std::string> list_of_attack_names);
    ~List_of_attacks() {}
    
    // lists out the name of the three possible attack options
    void list_attacks();
    
    // update functions for primary_attacks
    // this function updates damage for primary_attacks
    void update_damage(int strength_stat, int weapon_damage_stat) { m_primary_attack.update_damage(weapon_damage_stat + strength_stat); }
    // this function updates the amount of ammo a weapon uses
    void update_ammo_usage(int weapon_ammo_count) { m_primary_attack.update_ammo_usage(weapon_ammo_count); }
    // this function updates the speed of the attack
    void update_base_attack_speed(int weapon_attack_speed) { m_primary_attack.update_base_attack_speed(weapon_attack_speed); }
    
    // The three classes that make up the struct
    Primary_attacks m_primary_attack;
    // pointer to Ultimate attacks and Item attacks to 
    // allow for polymorphism 
    // TO BE IMPLEMENTED WHEN ULTIMATE ATTACKS AND ITEMS ARE DESIGNED
    std::shared_ptr<Ultimate_attacks> pm_ult;
    std::shared_ptr<Item_attack> pm_use_offensive_item;
    // convienent collection of attack names
    // Primary Attack is index 0 by default
    // Ultimate Attack is index 1
    // Items is index 2
    std::vector<std::string> m_list_of_attack_names;
    std::vector<bool> m_possible_attacks;
};

#endif // ATTACKS_H