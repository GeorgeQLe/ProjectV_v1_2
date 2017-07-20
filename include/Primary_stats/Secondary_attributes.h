/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes class and its member function
*/
#ifndef SECONDARY_ATTRIBUTE_H
#define SECONDARY_ATTRIBUTE_H

#include "Primary_stats/Secondary_attributes_strength.h"
#include "Primary_stats/Secondary_attributes_leadership.h"
#include "Primary_stats/Secondary_attributes_intelligence.h"
#include "Primary_stats/Secondary_attributes_character.h"
#include "Primary_stats/Secondary_attributes_endurance.h"

class Secondary_attributes : protected Secondary_attributes_strength_based, protected Secondary_attributes_leadership_based,
							protected Secondary_attributes_intelligence_based, protected Secondary_attributes_character_based,
							protected Secondary_attributes_endurance_based
				
{
	public:
	Secondary_attributes();
	
	// used for character creation
	void set_secondary_attributes(int strength, int leadership, int intelligence, int character, int endurance); 
	// used after level up
	void update_stats(int strength, int leadership, int intelligence, int character, int endurance); 
	
	void reduce_reputation(int amount);
	void increase_reputation(int amount);
};

#endif