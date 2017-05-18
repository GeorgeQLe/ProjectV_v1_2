#ifndef ATTACKS_H
#define ATTACKS_H

struct Attack_stats
{
    Attack_stats(int damage, int ammo_usage, int base_attack_speed)
    : m_damage(damage), m_ammo_usage(ammo_usage), m_base_attack_speed(base_attack_speed) {}
    int m_damage; // damage is an int to interact with current health total
    int m_ammo_usage; // amount of weapon capacity the attack uses up
    int m_base_attack_speed; // speed of attack without character modifier
};

class Attacks
{
    public:
    Attacks(int damage, int ammo_usage, int base_attack_speed)
    : m_stats(damage, ammo_usage, base_attack_speed) {}
    
    void update();
    
    private:
    Attack_stats m_stats;
};

class Primary_attacks: public Attacks
{
    public:
    Primary_attacks(int damage, int ammo_usage, int base_attack_speed) 
    : Attacks(damage, ammo_usage, base_attack_speed) {}
};

class Ultimate_attacks: public Attacks
{
    public:
    Ultimate_attacks(int damage, int ammo_usage, int base_attack_speed, bool ready) 
    : Attacks(damage, ammo_usage, base_attack_speed), m_ready(ready) {}
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    void special_effect();
    private:
    bool m_ready; // has ultimate attack been charged yet? true is ready for use, 
                // false is obvious
};

class Item_attack: public Attacks
{
    public:
    Item_attack(int damage, int ammo_usage, int base_attack_speed) 
    : Attacks(damage, ammo_usage, base_attack_speed) {}
    
    // Similar to ultimate attacks, usually much weaker
    void effect();
};

struct List_of_attacks
{
    List_of_attacks() : m_primary_attack(0, 0, 0), m_ult(0, 0, false, 0), m_use_offensive_item(0, 0, 0) {}
    Primary_attacks m_primary_attack;
    Ultimate_attacks m_ult;
    Item_attack m_use_offensive_item;
};

#endif