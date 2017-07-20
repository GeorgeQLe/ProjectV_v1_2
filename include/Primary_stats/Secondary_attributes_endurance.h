/*  Copyright 2017 George Le
    Declaration of the Secondary_attributes_endurance_based class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_ENDURANCE_H
#define SECONDARY_ATTRIBUTE_ENDURANCE_H

class Secondary_attributes_endurance_based
{
	public:
	Secondary_attributes_endurance_based();
	Secondary_attributes_endurance_based(unsigned int stamina, unsigned int health_regeneration, 
										unsigned int speed_modifier, unsigned int armor_resistance);
	
	//accessor functions
	unsigned int stamina() const { return m_stamina; }
	unsigned int health_regeneration() const { return m_health_regeneration; }
	unsigned int speed_modifier() const { return m_speed_modifier; }
	unsigned int armor_resistance() const { return m_armor_resistance; }
	
	// calls all four of the below functions, used in character creation or level ups
	void calculate_endurance_based_attributes(int endurance);
	
	//endurance based attribute mutators
	void calculate_stamina_stat(int endurance);
	void calculate_health_regeneration_stat(int endurance);
	void calculate_speed_modifier_stat(int endurance);
	void calculate_armor_resistance(int endurance);
	
	private:
	//endurance affects the ability for the player to perform actions, survive long term
    //engagements, and the rate at which players take actions. 
    //Potential addition: fatigue in travels
    unsigned int m_stamina;
    unsigned int m_health_regeneration;
    unsigned int m_speed_modifier;
    unsigned int m_armor_resistance; //modified by gear
};

#endif