/*	Copyright 2016 George Le
	Primary stats have two components primary and secondary attributes.
	Secondary attributes are split into five different classes for each of the attributes.
*/
#ifndef PRIMARY_STATS_H
#define PRIMARY_STATS_H

#include "Primary_stats/Primary_attributes.h"
#include "Primary_stats/Secondary_attributes.h"

class CPrimaryStats : public CPrimaryAttributes, public CSecondaryAttributes
{
	public:
	// default constructor
	CPrimaryStats() : m_level(1), m_experience_points(0), m_experience_points_needed(100), m_total_health(10), 
					m_current_health_total(10), m_defense(0), m_speed(1) {}
	// simple constructor for hostiles
	CPrimaryStats(int difficulty, unsigned int level, unsigned int total_health, int current_carry_amount, unsigned int defense,
					unsigned int speed);
	// constructor for combat_entities
	CPrimaryStats(int strength, int leadership, int intelligence, int character, int endurance, unsigned int level, 
				unsigned int total_health, int current_health_total, unsigned int defense, unsigned int speed);
	// called in character_setup.h to initialize primary stats for players
	void InitPrimaryStats(int strength, int leadership, int intelligence, int character, int endurance);
	// function to level up the player
	void LevelUp(unsigned int experience_points_granted);
	
	// accessor functions
	unsigned int Level() const { return m_level; }
	unsigned int ExperiencePoints() const { return m_experience_points; }
	unsigned int ExperiencePointsNeeded() const { return m_experience_points_needed; }
	unsigned int TotalHealth() const { return m_total_health; }
	unsigned int CurrentHealthTotal() const { return m_current_health_total; }
	unsigned int Defense() const { return m_defense; }
	unsigned int Speed() const { return m_speed; }
	
	// mutator functions
	void ReduceReputation(int amount);
	void IncreaseReputation(int amount);

	// function controlling taking damage
	// returns true if the character took damage, false if error or attack
	// did no damage
	bool TakeDamage(int damage);
	
	// heals the character
	void Heal(int heal_amount);
	
	// fully heals the character
	void FullHeal() { m_current_health_total = m_total_health; }
	
	private:
	//general stats
	unsigned int m_level;
	unsigned int m_experience_points;
	unsigned int m_experience_points_needed;
	
	//health related variables
	unsigned int m_total_health;
	int m_current_health_total; // not unsigned bc it can be negative much to the player's chagrin
	
	// combat stats modified by weapons and armor
	unsigned int m_defense;
	unsigned int m_speed;
};

#endif