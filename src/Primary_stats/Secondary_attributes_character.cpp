/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryAttributesCharacterBased class
*/
#include <math.h>
#include "Primary_stats/Secondary_attributes_character.h"

CSecondaryAttributesCharacterBased::CSecondaryAttributesCharacterBased() 
                : m_suave(0), m_reputation(0), m_presence(0), m_deception(1) 
{
    
}

CSecondaryAttributesCharacterBased::CSecondaryAttributesCharacterBased(int suave, int reputation, int presence, unsigned int deception) 
		: m_suave{suave}, m_reputation{reputation}, m_presence{presence}, m_deception{deception} 
{
    
}

// function for setting up and updating character based secondary attributes
void CSecondaryAttributesCharacterBased::CalculateCharacterBasedAttributes(int character)
{
	CalculateSuaveStat(character);
	CalculateReputationStat(character);
	CalculatePresenceStat(character);
	CalculateDeceptionStat(character);
}

void CSecondaryAttributesCharacterBased::CalculateSuaveStat(int character)
{
	m_suave = static_cast<int>(floor((character * 0.5) + 1));
}

void CSecondaryAttributesCharacterBased::CalculateReputationStat(int character)
{
	m_reputation = static_cast<int>(floor((character * 0.5) + 1));
}

void CSecondaryAttributesCharacterBased::CalculatePresenceStat(int character)
{
	m_presence = static_cast<int>(floor((character * 0.5) + 1));
}

void CSecondaryAttributesCharacterBased::CalculateDeceptionStat(int character)
{
	m_deception = static_cast<int>(floor((character * 0.5) + 1));
}

void CSecondaryAttributesCharacterBased::ReduceReputation(int amount)
{
	m_reputation-=amount;
}

void CSecondaryAttributesCharacterBased::IncreaseReputation(int amount)
{
	m_reputation+=amount;
}