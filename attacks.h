/*  Copyright 2017 George Le
    
*/
#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>
#include <vector>

enum Stat { DAMAGE = 1, AMMO, SPEED};

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
    
    void update(Stat to_be_changed, int new_stat_amount);
    int get_stat(Stat to_be_returned);
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
};

class Ultimate_attacks: public Attacks
{
    public:
    Ultimate_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool ready) 
    : Attacks(name, damage, ammo_usage, base_attack_speed, ready) {}
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    void special_effect() {}
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
    
    // The three classes that make up the struct
    Primary_attacks m_primary_attack;
    // pointer to Ultimate attacks and Item attacks to 
    // allow for polymorphism 
    // TO BE IMPLEMENTED WHEN ULTIMATE ATTACKS AND ITEMS ARE DESIGNED
    Ultimate_attacks* m_ult;
    Item_attack* m_use_offensive_item;
    // convienent collection of attack names
    // Primary Attack is index 0 by default
    // Ultimate Attack is index 1
    // Items is index 2
    std::vector<std::string> m_list_of_attack_names;
    std::vector<bool> m_possible_attacks;
};

#endif // ATTACKS_H