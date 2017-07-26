/*  Copyright 2017 George Le
    Declaration of the CSecondaryAttributesStrengthBased class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_STRENGTH_H
#define SECONDARY_ATTRIBUTE_STRENGTH_H

class CSecondaryAttributesStrengthBased
{
	public:
	CSecondaryAttributesStrengthBased();
	CSecondaryAttributesStrengthBased(int health_modifier, int attack_modifier, unsigned int base_carry_limit, 
										unsigned int current_carry_amount);
	
		//accessor functions
	int health_modifier() const { return m_health_modifier; }
	int attack_modifier() const { return m_attack_modifier; }
	unsigned int BaseCarryLimit() const { return m_base_carry_limit; }
	unsigned int CurrentCarryAmount() const { return m_current_carry_amount; }
	
	// calls all four of the below functions, used in character creation or level ups
	void CalculateStrengthBasedAttributes(int strength);
	
	//strength based attribute mutators
	void CalculateHealthModifier(int strength);
	void CalculateAttackModifier(int strength);
	void CalculateBaseCarryAmount(int strength);
	bool SetCurrentCarryAmount(unsigned int new_carry_amount);
	
	private:
	//strength - big angry bang bang pick things up put things down
	//strength related variables
	int m_health_modifier; //double? also not unsigned bc you can have a negative modifier(thanks DnD)
	int m_attack_modifier;
	unsigned int m_base_carry_limit; //unsigned bc why would you have negative carry capacity?
	unsigned int m_current_carry_amount;
};

#endif