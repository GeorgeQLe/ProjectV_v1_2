#ifndef ATTACKS_H
#define ATTACKS_H

struct Primary_attacks
{
    Primary_attacks(int damage, int ammo_usage, int base_attack_speed) 
    : m_damage(damage), m_ammo_usage(ammo_usage), m_base_attack_speed(base_attack_speed) {}
    
    int m_damage; // damage is an int to interact with current health total
    int m_ammo_usage; // amount of weapon capacity the attack uses up
    int m_base_attack_speed; // speed of attack without character modifier
};

struct Ultimate_attacks
{
    Ultimate_attacks(int damage, int ammo_usage, bool ready, int base_attack_speed) 
    : m_damage(damage), m_ammo_usage(ammo_usage), m_ready(ready),
    m_base_attack_speed(base_attack_speed) {}
    int m_damage; // same as primary attack
    int m_ammo_usage; // same as primary attack
    bool m_ready; // has ultimate attack been charged yet? true is ready for use, 
                // false is obvious
    int m_base_attack_speed; // same as primary attack
    
    // Ultimate attacks can have special effects that are triggered and 
    // controlled by this function
    void special_effect();
};

struct Item_attack
{
    Item_attack(int damage, int ammo_usage, int base_attack_speed) 
    : m_damage(damage), m_ammo_usage(ammo_usage), m_base_attack_speed(base_attack_speed) {}   
    int m_damage; // same as primary attack
    int m_consumption_amount; // amount of uses of current action
    int m_base_attack_speed; // same as primary attack
    
    // Similar to ultimate attacks, usually much weaker
    void effect();
};

class Attacks
{
    public:
    Attacks() : m_primary_attack(0, 0, 0), m_ult(0, 0, false, 0), m_use_offensive_item(0, 0, 0) {}
    
    void update();
    private:
    Primary_attacks m_primary_attack;
    Ultimate_attacks m_ult;
    Item_attack m_use_offensive_item;
};

#endif