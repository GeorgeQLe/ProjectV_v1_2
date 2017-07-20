/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_attributes_endurance_based class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_endurance.h"

Secondary_attributes_endurance_based::Secondary_attributes_endurance_based() 
        : m_stamina(10), m_health_regeneration(1), m_speed_modifier(1), m_armor_resistance(1) 
{
    
}

Secondary_attributes_endurance_based::Secondary_attributes_endurance_based(unsigned int stamina, unsigned int health_regeneration, 
									unsigned int speed_modifier, unsigned int armor_resistance) 
		: m_stamina{stamina}, m_health_regeneration{health_regeneration}, m_speed_modifier{speed_modifier}, 
		m_armor_resistance{armor_resistance} 
{
    
}

// function for setting up and updating endurance based secondary attributes
void Secondary_attributes_endurance_based::calculate_endurance_based_attributes(int endurance)
{
	calculate_stamina_stat(endurance);
	calculate_health_regeneration_stat(endurance);
	calculate_speed_modifier_stat(endurance);
	calculate_armor_resistance(endurance);
}

void Secondary_attributes_endurance_based::calculate_stamina_stat(int endurance)
{
	m_stamina = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void Secondary_attributes_endurance_based::calculate_health_regeneration_stat(int endurance)
{
	m_health_regeneration = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void Secondary_attributes_endurance_based::calculate_speed_modifier_stat(int endurance)
{
	m_speed_modifier = static_cast<unsigned int>(floor((endurance * 0.5) + 1));	
}

void Secondary_attributes_endurance_based::calculate_armor_resistance(int endurance)
{
	m_armor_resistance = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}