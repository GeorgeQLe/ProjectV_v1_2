/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryAttributesIntelligenceBased class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_intelligence.h"

CSecondaryAttributesIntelligenceBased::CSecondaryAttributesIntelligenceBased() : m_sciences_stat(1), m_social_sciences_stat(1),
												m_tinkering_stat(1), m_tech_savvy_stat(1) 
{
    
}

CSecondaryAttributesIntelligenceBased::CSecondaryAttributesIntelligenceBased(int sciences_stat, int social_sciences_stat, 
											int tinkering_stat, int tech_savvy_stat) : 
											m_sciences_stat{sciences_stat}, m_social_sciences_stat{social_sciences_stat}, 
											m_tinkering_stat{tinkering_stat}, m_tech_savvy_stat{tech_savvy_stat} 
{
    
}

// function for setting up and updating intelligence based secondary attributes
void CSecondaryAttributesIntelligenceBased::CalculateIntelligenceBasedAttributes(int leadership)
{
	CalculateScienceStat(leadership);
	CalculateSocialSciencesStat(leadership);
	CalculateTinkeringStat(leadership);
	CalculateTechSavvyStat(leadership);
}

void CSecondaryAttributesIntelligenceBased::CalculateScienceStat(int intelligence)
{
	m_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void CSecondaryAttributesIntelligenceBased::CalculateSocialSciencesStat(int intelligence)
{
	m_social_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void CSecondaryAttributesIntelligenceBased::CalculateTinkeringStat(int intelligence)
{
	m_tinkering_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void CSecondaryAttributesIntelligenceBased::CalculateTechSavvyStat(int intelligence)
{
	m_tech_savvy_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}