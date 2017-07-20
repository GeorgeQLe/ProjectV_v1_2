/*	Copyright 2016 George Le
	Definitions of the member functions for the Primary_stats class
*/
#include <iostream>
#include <cmath>
#include "Primary_stats/Primary_stats.h"

// function only to be used in leveling up
void print_to_screen_level_up(unsigned int current_level, unsigned int experience_points, unsigned int experience_points_needed)
{
	std::cout << "Congratulations, you have leveled up to level " << current_level << "!\n";
	std::cout << experience_points << "/" << experience_points_needed << std::endl;
}

Primary_stats::Primary_stats(int difficulty, unsigned int level, unsigned int total_health, int current_health_total, 
							unsigned int defense, unsigned int speed)
							: Primary_attributes(difficulty, difficulty, difficulty, difficulty, difficulty),
							m_level(level), m_total_health(total_health), m_current_health_total(current_health_total),
							m_defense(defense), m_speed(speed)
{
	// modify_stat is a member function of Primary_attributes
	modify_stat(STRENGTH, m_level);
	modify_stat(LEADERSHIP, m_level);
	modify_stat(INTELLIGENCE, m_level);
	modify_stat(LEADERSHIP, m_level);
	modify_stat(ENDURANCE, m_level);
}							

Primary_stats::Primary_stats(int strength, int leadership, int intelligence, int character, int endurance, unsigned int level,
					unsigned int total_health, int current_health_total, unsigned int defense, unsigned int speed) 
					: Primary_attributes(strength, leadership, intelligence, character, endurance), m_level(level), 
					m_total_health(total_health), m_current_health_total(current_health_total), m_defense(defense), m_speed(speed)
{
	// member function of Primary_attributes
	modify_stat(STRENGTH, m_level);
	modify_stat(LEADERSHIP, m_level);
	modify_stat(INTELLIGENCE, m_level);
	modify_stat(LEADERSHIP, m_level);
	modify_stat(ENDURANCE, m_level);
}

void Primary_stats::init_primary_stats(int strength, int leadership, int intelligence, 
												int character, int endurance)
{
	// member function of Primary_attributes
	modify_stat(STRENGTH, strength);
	modify_stat(LEADERSHIP, leadership);
	modify_stat(INTELLIGENCE, intelligence);
	modify_stat(CHARACTER, character);
	modify_stat(ENDURANCE, endurance);
	
	// // member function of Secondary_attributes
	set_secondary_attributes(this->strength(), this->leadership(), this->intelligence(), this->character(), this->endurance());
	
	m_experience_points = 0;
	m_experience_points_needed = 100;
	m_total_health+=(static_cast<unsigned int>(floor(strength * 0.35)));
	m_current_health_total = m_total_health;
	m_defense+=(static_cast<unsigned int>(floor(endurance * 0.5)));
	m_speed+=(static_cast<unsigned int>(floor(endurance * 0.5)));
}

void Primary_stats::level_up(unsigned int experience_points_granted)
{
	m_experience_points+=experience_points_granted;
	
	while(m_experience_points > m_experience_points_needed)
	{
		++m_level;
		m_experience_points-=m_experience_points_needed;

		print_to_screen_level_up(m_level, m_experience_points, m_experience_points_needed);
		
		m_experience_points_needed*=m_level;
	}
}

void Primary_stats::reduce_reputation(int amount)
{
	reduce_reputation(amount);
}

void Primary_stats::increase_reputation(int amount)
{
	increase_reputation(amount);
}

bool Primary_stats::take_damage(int damage) 
{
	if((m_current_health_total-damage) >= 0 && damage > 0) 
	{ 
		m_current_health_total-=damage; 
		return true;
	}
	else if(damage > 0)
	{
		m_current_health_total = 0;
		return true;
	}
	
	return false;
}

void Primary_stats::heal(int heal_amount)
{
	if(static_cast<unsigned int>(m_current_health_total+heal_amount) <= m_total_health)
	{
		m_current_health_total+=heal_amount;
	}
}