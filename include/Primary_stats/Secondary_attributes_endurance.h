/*  Copyright 2017 George Le
    Declaration of the CSecondaryAttributesEnduranceBased class and its member functions
*/
#ifndef SECONDARY_ATTRIBUTE_ENDURANCE_H
#define SECONDARY_ATTRIBUTE_ENDURANCE_H

class CSecondaryAttributesEnduranceBased
{
	public:
	CSecondaryAttributesEnduranceBased();
	CSecondaryAttributesEnduranceBased(unsigned int stamina, unsigned int health_regeneration, 
										unsigned int speed_modifier, unsigned int armor_resistance);
	
	//accessor functions
	unsigned int Stamina() const { return m_stamina; }
	unsigned int HealthRegeneration() const { return m_health_regeneration; }
	unsigned int SpeedModifier() const { return m_speed_modifier; }
	unsigned int ArmorResistance() const { return m_armor_resistance; }
	
	// calls all four of the below functions, used in character creation or level ups
	void CalculateEnduranceBasedAttributes(int endurance);
	
	//endurance based attribute mutators
	void CalculateStaminaStat(int endurance);
	void CalculateHealthRegenerationStat(int endurance);
	void CalculateSpeedModifierStat(int endurance);
	void CalculateArmorResistance(int endurance);
	
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