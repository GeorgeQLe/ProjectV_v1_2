/*  Copyright 2017 George Le
    Declaration of the CSecondaryAttributesLeadershipBased class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_LEADERSHIP_H
#define SECONDARY_ATTRIBUTE_LEADERSHIP_H

class CSecondaryAttributesLeadershipBased
{
	public:
	CSecondaryAttributesLeadershipBased();
	CSecondaryAttributesLeadershipBased(int friendly_morale_modifier, int strategy_stat, int tactical_stat, unsigned int nerves);
	
	//accessor functions
	int Friendly_morale() const { return m_friendly_morale_modifier; }
	int Strategy_stat() const { return m_strategy_stat; }
	int Tactical_stat() const { return m_tactical_stat; }
	unsigned int Nerves() const { return m_nerves; }
	
	// calls all four of the below functions, used in character creation or level ups
	void CalculateLeadershipBasedAttributes(int leadership);
	
	//leadership based attribute mutators
	void CalculateFriendlyMoraleModifier(int leadership);
	void CalculateStrategyStat(int leadership);
	void CalculateTacticalStat(int leadership);
	void CalculateNervesStat(int leadership);
	
	private:
	//leadership stat with two general paths though both can be utilized
    //morale and strategy both bolster general-style play 
    //tactical and morale to a minor extent bolster squad to individual play
    //stat for the effect player has on friendly troops (inspire)
    //also includes your morale and cunning
	int m_friendly_morale_modifier;
	int m_strategy_stat;
	int m_tactical_stat;
	unsigned int m_nerves;
};

#endif