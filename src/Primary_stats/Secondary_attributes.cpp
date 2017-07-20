/*  Copyright 2017 George Le
    Definition of the member functions of the Secondary_attributes class
*/
#include "Primary_stats/Secondary_attributes.h"

Secondary_attributes::Secondary_attributes()
{
    // Empty constructor other than initializer list
}

// function calling the "init" function for the derivative secondary_attribute classes
void Secondary_attributes::set_secondary_attributes(int strength, int leadership, int intelligence, int character, int endurance)
{
	calculate_strength_based_attributes(strength);
	calculate_leadership_based_attributes(leadership);
	calculate_intelligence_based_attributes(intelligence);
	calculate_character_based_attributes(character);
	calculate_endurance_based_attributes(endurance);	
}

// function to update the derivative secondary_attribute classes 
void Secondary_attributes::update_stats(int strength, int leadership, int intelligence, int character, int endurance)
{
	calculate_strength_based_attributes(strength);
	calculate_leadership_based_attributes(leadership);
	calculate_intelligence_based_attributes(intelligence);
	calculate_character_based_attributes(character);
	calculate_endurance_based_attributes(endurance);
}

void Secondary_attributes::reduce_reputation(int amount)
{
	reduce_reputation(amount);
}

void Secondary_attributes::increase_reputation(int amount)
{
	increase_reputation(amount);
}