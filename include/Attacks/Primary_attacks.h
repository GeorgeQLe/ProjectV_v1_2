#ifndef PRIMARY_ATTACKS_H
#define PRIMARY_ATTACKS_H

#include "Attacks/Attacks.h"

class Primary_attacks: public Attacks
{
    public:
    Primary_attacks(std::string name, int damage, int ammo_usage, int base_attack_speed, bool usable);
    ~Primary_attacks();
};

#endif