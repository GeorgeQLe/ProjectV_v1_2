/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes_intelligence_based class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_INTELLIGENCE_H
#define SECONDARY_ATTRIBUTE_INTELLIGENCE_H

class Secondary_attributes_intelligence_based
{
	public:
	Secondary_attributes_intelligence_based();
	Secondary_attributes_intelligence_based(int sciences_stat, int social_sciences_stat, int tinkering_stat, int tech_savvy_stat);
	
	//accessor functions
	int science_stat() const { return m_sciences_stat; }
	int social_science_stat() const { return m_social_sciences_stat; }
	int tinkering_stat() const { return m_tinkering_stat; }
	int tech_stat() const { return m_tech_savvy_stat; }
	
	// calls all four of the below functions, used in character creation or level ups
	void calculate_intelligence_based_attributes(int intelligence);
	
	//intelligence based attribute mutators
	void calculate_science_stat(int leadership);
	void calculate_social_sciences_stat(int leadership);
	void calculate_tinkering_stat(int leadership);
	void calculate_tech_savvy_stat(int leadership);
	
	private:
	//intelligence affects the ability for the player to perform a certain function
    //though lower intelligence is perhaps not a bad thing due to the lack of 
    //potential of overthinking things
    //intelligence has three major areas that affect leadership and character
    //science affects the player's ability to perform abilities based on science,
    //medicine, mathematics, engineering, and computers.
	int m_sciences_stat;
	int m_social_sciences_stat;
	int m_tinkering_stat;
	int m_tech_savvy_stat;
};

#endif