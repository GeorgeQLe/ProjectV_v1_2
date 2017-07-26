/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryAttributesStrengthBased class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_strength.h"

CSecondaryAttributesStrengthBased::CSecondaryAttributesStrengthBased() 
        : m_health_modifier(1), m_attack_modifier(1), m_base_carry_limit(10), m_current_carry_amount(0) 
{
    
}
											
CSecondaryAttributesStrengthBased::CSecondaryAttributesStrengthBased(int health_modifier, int attack_modifier, 
        unsigned int base_carry_limit, unsigned int current_carry_amount) :
			m_health_modifier{health_modifier}, m_attack_modifier{attack_modifier}, m_base_carry_limit{base_carry_limit},
			m_current_carry_amount{current_carry_amount} 
{
    
}

// function for setting up and updating stength based secondary attributes
void CSecondaryAttributesStrengthBased::CalculateStrengthBasedAttributes(int strength)
{
	CalculateHealthModifier(strength);
	CalculateAttackModifier(strength);
	CalculateBaseCarryAmount(strength);
	SetCurrentCarryAmount(0);
}

void CSecondaryAttributesStrengthBased::CalculateHealthModifier(int strength)
{
	m_health_modifier = static_cast<int>(floor((strength * 0.4) + 1)); 
}

void CSecondaryAttributesStrengthBased::CalculateAttackModifier(int strength)
{
	m_attack_modifier = static_cast<int>(floor((strength * 0.29) + 1));
}

void CSecondaryAttributesStrengthBased::CalculateBaseCarryAmount(int strength)
{
	m_base_carry_limit = static_cast<unsigned int>(floor((strength * 0.72) + 1));
}

bool CSecondaryAttributesStrengthBased::SetCurrentCarryAmount(unsigned int new_carry_amount)
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