/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes_character_based class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_CHARACTER_H
#define SECONDARY_ATTRIBUTE_CHARACTER_H

class Secondary_attributes_character_based
{
	public:
	Secondary_attributes_character_based();
	Secondary_attributes_character_based(int suave, int reputation, int presence, unsigned int deception);
	
	//accessor functions
	int suave() const { return m_suave; }
	int reputation() const { return m_reputation; }
	int presence() const { return m_presence; }
	unsigned int deception() const { return m_deception; }
	
	// calls all four of the below functions, used in character creation or level ups
	void calculate_character_based_attributes(int character);
	
	//character based attribute mutators
	void calculate_suave_stat(int character);
	void calculate_reputation_stat(int character);
	void calculate_presence_stat(int character);
	void calculate_deception_stat(int character);
	
	// reputation shifts quicker than the other stats and thus can be modified
	// accordingly
	void reduce_reputation(int amount);
	void increase_reputation(int amount);
	
	private:
	//character affects the ability for the player to either positively or negatively affect 
    //the gamespace around them (environment, NPCs), interactions with advisors, general NPC conversations,
    //and diplomacy, and initial reputation to unmet NPCs and factions.
    int m_suave;
    int m_reputation;
    int m_presence; 
    unsigned int m_deception;
};

#endif