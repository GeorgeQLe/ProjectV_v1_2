/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_attributes_strength_based class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_strength.h"

Secondary_attributes_strength_based::Secondary_attributes_strength_based() 
        : m_health_modifier(1), m_attack_modifier(1), m_base_carry_limit(10), m_current_carry_amount(0) 
{
    
}
											
Secondary_attributes_strength_based::Secondary_attributes_strength_based(int health_modifier, int attack_modifier, 
        unsigned int base_carry_limit, unsigned int current_carry_amount) :
			m_health_modifier{health_modifier}, m_attack_modifier{attack_modifier}, m_base_carry_limit{base_carry_limit},
			m_current_carry_amount{current_carry_amount} 
{
    
}

// function for setting up and updating stength based secondary attributes
void Secondary_attributes_strength_based::calculate_strength_based_attributes(int strength)
{
	calculate_health_modifier(strength);
	calculate_attack_modifier(strength);
	calculate_base_carry_amount(strength);
	set_current_carry_amount(0);
}

void Secondary_attributes_strength_based::calculate_health_modifier(int strength)
{
	m_health_modifier = static_cast<int>(floor((strength * 0.4) + 1)); 
}

void Secondary_attributes_strength_based::calculate_attack_modifier(int strength)
{
	m_attack_modifier = static_cast<int>(floor((strength * 0.29) + 1));
}

void Secondary_attributes_strength_based::calculate_base_carry_amount(int strength)
{
	m_base_carry_limit = static_cast<unsigned int>(floor((strength * 0.72) + 1));
}

bool Secondary_attributes_strength_based::set_current_carry_amount(unsigned int new_carry_amount)
{
	if(new_carry_amount > 0)
	{
		if((static_cast<unsigned int>(new_carry_amount) > m_base_carry_limit))
		{
			return false;
		}
	}
	m_current_carry_amount = static_cast<unsigned int>(new_carry_amount);
	return true;
}