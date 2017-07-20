/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes_strength_based class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_STRENGTH_H
#define SECONDARY_ATTRIBUTE_STRENGTH_H

class Secondary_attributes_strength_based
{
	public:
	Secondary_attributes_strength_based();
	Secondary_attributes_strength_based(int health_modifier, int attack_modifier, unsigned int base_carry_limit, 
										unsigned int current_carry_amount);
	
		//accessor functions
	int health_modifier() const { return m_health_modifier; }
	int attack_modifier() const { return m_attack_modifier; }
	unsigned int base_carry_limit() const { return m_base_carry_limit; }
	unsigned int current_carry_amount() const { return m_current_carry_amount; }
	
	// calls all four of the below functions, used in character creation or level ups
	void calculate_strength_based_attributes(int strength);
	
	//strength based attribute mutators
	void calculate_health_modifier(int strength);
	void calculate_attack_modifier(int strength);
	void calculate_base_carry_amount(int strength);
	bool set_current_carry_amount(unsigned int new_carry_amount);
	
	private:
	//strength - big angry bang bang pick things up put things down
	//strength related variables
	int m_health_modifier; //double? also not unsigned bc you can have a negative modifier(thanks DnD)
	int m_attack_modifier;
	unsigned int m_base_carry_limit; //unsigned bc why would you have negative carry capacity?
	unsigned int m_current_carry_amount;
};

#endif