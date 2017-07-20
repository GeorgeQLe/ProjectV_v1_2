/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_attributes_character_based class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_character.h"

Secondary_attributes_character_based::Secondary_attributes_character_based() 
                : m_suave(0), m_reputation(0), m_presence(0), m_deception(1) 
{
    
}

Secondary_attributes_character_based::Secondary_attributes_character_based(int suave, int reputation, int presence, 
										unsigned int deception) 
		: m_suave{suave}, m_reputation{reputation}, m_presence{presence}, m_deception{deception} 
{
    
}

// function for setting up and updating character based secondary attributes
void Secondary_attributes_character_based::calculate_character_based_attributes(int character)
{
	calculate_suave_stat(character);
	calculate_reputation_stat(character);
	calculate_presence_stat(character);
	calculate_deception_stat(character);
}

void Secondary_attributes_character_based::calculate_suave_stat(int character)
{
	m_suave = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_reputation_stat(int character)
{
	m_reputation = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_presence_stat(int character)
{
	m_presence = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_deception_stat(int character)
{
	m_deception = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::reduce_reputation(int amount)
{
	m_reputation-=amount;
}

void Secondary_attributes_character_based::increase_reputation(int amount)
{
	m_reputation+=amount;
}