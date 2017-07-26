/*  Copyright 2017 George Le
    Definition of the member functions of the CSecondaryAttributes class
*/
#include "Primary_stats/Secondary_attributes.h"

CSecondaryAttributes::CSecondaryAttributes()
{
    // Empty constructor other than initializer list
}

// function calling the "init" function for the derivative secondary_attribute classes
void CSecondaryAttributes::SetSecondaryAttributes(int strength, int leadership, int intelligence, int character, int endurance)
{
	CalculateStrengthBasedAttributes(strength);
	CalculateLeadershipBasedAttributes(leadership);
	CalculateIntelligenceBasedAttributes(intelligence);
	CalculateCharacterBasedAttributes(character);
	CalculateEnduranceBasedAttributes(endurance);	
}

// function to update the derivative secondary_attribute classes 
void CSecondaryAttributes::UpdateStats(int strength, int leadership, int intelligence, int character, int endurance)
{
	CalculateStrengthBasedAttributes(strength);
	CalculateLeadershipBasedAttributes(leadership);
	CalculateIntelligenceBasedAttributes(intelligence);
	CalculateCharacterBasedAttributes(character);
	CalculateEnduranceBasedAttributes(endurance);	
}

void CSecondaryAttributes::ReduceReputation(int amount)
{
	ReduceReputation(amount);
}

void CSecondaryAttributes::IncreaseReputation(int amount)
{
	IncreaseReputation(amount);
}