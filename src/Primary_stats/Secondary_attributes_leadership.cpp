/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryAttributesLeadershipBased class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_leadership.h"

CSecondaryAttributesLeadershipBased::CSecondaryAttributesLeadershipBased() : m_friendly_morale_modifier(1), m_strategy_stat(1), 
											m_tactical_stat(1), m_nerves(1) 
{
    
}

CSecondaryAttributesLeadershipBased::CSecondaryAttributesLeadershipBased(int friendly_morale_modifier, int strategy_stat, 
                                    int tactical_stat, unsigned int nerves) : m_friendly_morale_modifier{friendly_morale_modifier}, 
                                    m_strategy_stat{strategy_stat}, m_tactical_stat{tactical_stat}, m_nerves{nerves} 
{
    
}

// function for setting up and updating leadership based secondary attributes
void CSecondaryAttributesLeadershipBased::CalculateLeadershipBasedAttributes(int leadership)
{
	CalculateFriendlyMoraleModifier(leadership);
	CalculateStrategyStat(leadership);
	CalculateTacticalStat(leadership);
	CalculateNervesStat(leadership);
}

void CSecondaryAttributesLeadershipBased::CalculateFriendlyMoraleModifier(int leadership)
{
	m_friendly_morale_modifier = static_cast<int>(floor((leadership * 0.3) + 1));
}

void CSecondaryAttributesLeadershipBased::CalculateStrategyStat(int leadership)
{
	m_strategy_stat = static_cast<int>(floor((leadership * 0.3) + 1));	
}

void CSecondaryAttributesLeadershipBased::CalculateTacticalStat(int leadership)
{
	m_tactical_stat = static_cast<int>(floor((leadership * 0.3) + 1));
}

void CSecondaryAttributesLeadershipBased::CalculateNervesStat(int leadership)
{
	m_nerves = static_cast<unsigned int>(floor((leadership * 0.5) + 1));
}