/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_attributes_intelligence_based class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_intelligence.h"

Secondary_attributes_intelligence_based::Secondary_attributes_intelligence_based() : m_sciences_stat(1), m_social_sciences_stat(1),
												m_tinkering_stat(1), m_tech_savvy_stat(1) 
{
    
}

Secondary_attributes_intelligence_based::Secondary_attributes_intelligence_based(int sciences_stat, int social_sciences_stat, 
											int tinkering_stat, int tech_savvy_stat) : 
											m_sciences_stat{sciences_stat}, m_social_sciences_stat{social_sciences_stat}, 
											m_tinkering_stat{tinkering_stat}, m_tech_savvy_stat{tech_savvy_stat} 
{
    
}

// function for setting up and updating intelligence based secondary attributes
void Secondary_attributes_intelligence_based::calculate_intelligence_based_attributes(int leadership)
{
	calculate_science_stat(leadership);
	calculate_social_sciences_stat(leadership);
	calculate_tinkering_stat(leadership);
	calculate_tech_savvy_stat(leadership);
}

void Secondary_attributes_intelligence_based::calculate_science_stat(int intelligence)
{
	m_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_social_sciences_stat(int intelligence)
{
	m_social_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_tinkering_stat(int intelligence)
{
	m_tinkering_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_tech_savvy_stat(int intelligence)
{
	m_tech_savvy_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}