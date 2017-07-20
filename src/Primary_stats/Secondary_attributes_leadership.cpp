/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_attributes_leadership_based class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_leadership.h"

Secondary_attributes_leadership_based::Secondary_attributes_leadership_based() : m_friendly_morale_modifier(1), m_strategy_stat(1), 
											m_tactical_stat(1), m_nerves(1) 
{
    
}

Secondary_attributes_leadership_based::Secondary_attributes_leadership_based(int friendly_morale_modifier, int strategy_stat, 
                                    int tactical_stat, unsigned int nerves) : m_friendly_morale_modifier{friendly_morale_modifier}, 
                                    m_strategy_stat{strategy_stat}, m_tactical_stat{tactical_stat}, m_nerves{nerves} 
{
    
}

// function for setting up and updating leadership based secondary attributes
void Secondary_attributes_leadership_based::calculate_leadership_based_attributes(int leadership)
{
	calculate_friendly_morale_modifier(leadership);
	calculate_strategy_stat(leadership);
	calculate_tactical_stat(leadership);
	calculate_nerves_stat(leadership);
}

void Secondary_attributes_leadership_based::calculate_friendly_morale_modifier(int leadership)
{
	m_friendly_morale_modifier = static_cast<int>(floor((leadership * 0.3) + 1));
}

void Secondary_attributes_leadership_based::calculate_strategy_stat(int leadership)
{
	m_strategy_stat = static_cast<int>(floor((leadership * 0.3) + 1));	
}

void Secondary_attributes_leadership_based::calculate_tactical_stat(int leadership)
{
	m_tactical_stat = static_cast<int>(floor((leadership * 0.3) + 1));
}

void Secondary_attributes_leadership_based::calculate_nerves_stat(int leadership)
{
	m_nerves = static_cast<unsigned int>(floor((leadership * 0.5) + 1));
}