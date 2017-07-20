/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes_leadership_based class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_LEADERSHIP_H
#define SECONDARY_ATTRIBUTE_LEADERSHIP_H

class Secondary_attributes_leadership_based
{
	public:
	Secondary_attributes_leadership_based();
	Secondary_attributes_leadership_based(int friendly_morale_modifier, int strategy_stat, int tactical_stat, unsigned int nerves);
	
	//accessor functions
	int friendly_morale() const { return m_friendly_morale_modifier; }
	int strategy_stat() const { return m_strategy_stat; }
	int tactical_stat() const { return m_tactical_stat; }
	unsigned int nerves() const { return m_nerves; }
	
	// calls all four of the below functions, used in character creation or level ups
	void calculate_leadership_based_attributes(int leadership);
	
	//leadership based attribute mutators
	void calculate_friendly_morale_modifier(int leadership);
	void calculate_strategy_stat(int leadership);
	void calculate_tactical_stat(int leadership);
	void calculate_nerves_stat(int leadership);
	
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