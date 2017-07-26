/*  Copyright 2017 George Le
    Declaration of the CSecondaryAttributes class and its member function
*/
#ifndef SECONDARY_ATTRIBUTE_H
#define SECONDARY_ATTRIBUTE_H

#include "Primary_stats/Secondary_attributes_strength.h"
#include "Primary_stats/Secondary_attributes_leadership.h"
#include "Primary_stats/Secondary_attributes_intelligence.h"
#include "Primary_stats/Secondary_attributes_character.h"
#include "Primary_stats/Secondary_attributes_endurance.h"

class CSecondaryAttributes : protected CSecondaryAttributesStrengthBased, protected CSecondaryAttributesLeadershipBased,
							protected CSecondaryAttributesIntelligenceBased, protected CSecondaryAttributesCharacterBased,
							protected CSecondaryAttributesEnduranceBased
				
{
	public:
	CSecondaryAttributes();
	
	// used for character creation
	void SetSecondaryAttributes(int strength, int leadership, int intelligence, int character, int endurance); 
	// used after level up
	void UpdateStats(int strength, int leadership, int intelligence, int character, int endurance); 
	
	void ReduceReputation(int amount);
	void IncreaseReputation(int amount);
};

#endif