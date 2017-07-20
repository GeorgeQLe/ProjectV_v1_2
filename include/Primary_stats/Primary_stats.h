/*	Copyright 2016 George Le
	Primary stats have two components primary and secondary attributes.
	Secondary attributes are split into five different classes for each of the attributes.
*/
#ifndef PRIMARY_STATS_H
#define PRIMARY_STATS_H

#include "Primary_stats/Primary_attributes.h"
#include "Primary_stats/Secondary_attributes.h"

class Primary_stats : public Primary_attributes, public Secondary_attributes
{
	public:
	// default constructor
	Primary_stats() : m_level(1), m_experience_points(0), m_experience_points_needed(100), m_total_health(10), 
					m_current_health_total(10), m_defense(0), m_speed(1) {}
	// simple constructor for hostiles
	Primary_stats(int difficulty, unsigned int level, unsigned int total_health, int current_carry_amount, unsigned int defense,
					unsigned int speed);
	// constructor for combat_entities
	Primary_stats(int strength, int leadership, int intelligence, int character, int endurance, unsigned int level, 
				unsigned int total_health, int current_health_total, unsigned int defense, unsigned int speed);
	// called in character_setup.h to initialize primary stats for players
	void init_primary_stats(int strength, int leadership, int intelligence, int character, int endurance);
	// function to level up the player
	void level_up(unsigned int experience_points_granted);
	
	// accessor functions
	unsigned int level() const { return m_level; }
	unsigned int experience_points() const { return m_experience_points; }
	unsigned int experience_points_needed() const { return m_experience_points_needed; }
	unsigned int total_health() const { return m_total_health; }
	unsigned int current_health_total() const { return m_current_health_total; }
	unsigned int defense() const { return m_defense; }
	unsigned int speed() const { return m_speed; }
	
	// mutator functions
	void reduce_reputation(int amount);
	void increase_reputation(int amount);

	// function controlling taking damage
	// returns true if the character took damage, false if error or attack
	// did no damage
	bool take_damage(int damage);
	
	// heals the character
	void heal(int heal_amount);
	
	// fully heals the character
	void full_heal() { m_current_health_total = m_total_health; }
	
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