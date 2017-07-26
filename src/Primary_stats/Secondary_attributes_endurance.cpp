/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryAttributesEnduranceBased class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_endurance.h"

CSecondaryAttributesEnduranceBased::CSecondaryAttributesEnduranceBased() 
        : m_stamina(10), m_health_regeneration(1), m_speed_modifier(1), m_armor_resistance(1) 
{
    
}

CSecondaryAttributesEnduranceBased::CSecondaryAttributesEnduranceBased(unsigned int stamina, unsigned int health_regeneration, 
									unsigned int speed_modifier, unsigned int armor_resistance) 
		: m_stamina{stamina}, m_health_regeneration{health_regeneration}, m_speed_modifier{speed_modifier}, 
		m_armor_resistance{armor_resistance} 
{
    
}

// function for setting up and updating endurance based secondary attributes
void CSecondaryAttributesEnduranceBased::CalculateEnduranceBasedAttributes(int endurance)
{
	CalculateStaminaStat(endurance);
	CalculateHealthRegenerationStat(endurance);
	CalculateSpeedModifierStat(endurance);
	CalculateArmorResistance(endurance);
}

void CSecondaryAttributesEnduranceBased::CalculateStaminaStat(int endurance)
{
	m_stamina = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void CSecondaryAttributesEnduranceBased::CalculateHealthRegenerationStat(int endurance)
{
	m_health_regeneration = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void CSecondaryAttributesEnduranceBased::CalculateSpeedModifierStat(int endurance)
{
	m_speed_modifier = static_cast<unsigned int>(floor((endurance * 0.5) + 1));	
}

void CSecondaryAttributesEnduranceBased::CalculateArmorResistance(int endurance)
{
	m_armor_resistance = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}