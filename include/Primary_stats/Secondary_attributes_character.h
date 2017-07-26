/*  Copyright 2017 George Le
    Declaration of the CSecondaryAttributesCharacterBased class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_CHARACTER_H
#define SECONDARY_ATTRIBUTE_CHARACTER_H

class CSecondaryAttributesCharacterBased
{
	public:
	CSecondaryAttributesCharacterBased();
	CSecondaryAttributesCharacterBased(int suave, int reputation, int presence, unsigned int deception);
	
	//accessor functions
	int Suave() const { return m_suave; }
	int Reputation() const { return m_reputation; }
	int Presence() const { return m_presence; }
	unsigned int Deception() const { return m_deception; }
	
	// calls all four of the below functions, used in character creation or level ups
	void CalculateCharacterBasedAttributes(int character);
	
	//character based attribute mutators
	void CalculateSuaveStat(int character);
	void CalculateReputationStat(int character);
	void CalculatePresenceStat(int character);
	void CalculateDeceptionStat(int character);
	
	// reputation shifts quicker than the other stats and thus can be modified
	// accordingly
	void ReduceReputation(int amount);
	void IncreaseReputation(int amount);
	
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