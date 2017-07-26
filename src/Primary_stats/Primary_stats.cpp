/*	Copyright 2016 George Le
	Definitions of the member functions for the CPrimaryStats class
*/
#include <iostream>
#include <cmath>
#include "Primary_stats/Primary_stats.h"

// function only to be used in leveling up
void PrintToScreenLevelUp(unsigned int current_level, unsigned int experience_points, unsigned int experience_points_needed)
{
	std::cout << "Congratulations, you have leveled up to level " << current_level << "!\n";
	std::cout << experience_points << "/" << experience_points_needed << std::endl;
}

CPrimaryStats::CPrimaryStats(int difficulty, unsigned int level, unsigned int total_health, int current_health_total, 
							unsigned int defense, unsigned int speed)
							: CPrimaryAttributes(difficulty, difficulty, difficulty, difficulty, difficulty),
							m_level(level), m_total_health(total_health), m_current_health_total(current_health_total),
							m_defense(defense), m_speed(speed)
{
	// ModifyStat is a member function of Primary_attributes
	ModifyStat(STRENGTH, m_level);
	ModifyStat(LEADERSHIP, m_level);
	ModifyStat(INTELLIGENCE, m_level);
	ModifyStat(LEADERSHIP, m_level);
	ModifyStat(ENDURANCE, m_level);
}							

CPrimaryStats::CPrimaryStats(int strength, int leadership, int intelligence, int character, int endurance, unsigned int level,
					unsigned int total_health, int current_health_total, unsigned int defense, unsigned int speed) 
					: CPrimaryAttributes(strength, leadership, intelligence, character, endurance), m_level(level), 
					m_total_health(total_health), m_current_health_total(current_health_total), m_defense(defense), m_speed(speed)
{
	// member function of Primary_attributes
	ModifyStat(STRENGTH, m_level);
	ModifyStat(LEADERSHIP, m_level);
	ModifyStat(INTELLIGENCE, m_level);
	ModifyStat(LEADERSHIP, m_level);
	ModifyStat(ENDURANCE, m_level);
}

void CPrimaryStats::InitPrimaryStats(int strength, int leadership, int intelligence, 
												int character, int endurance)
{
	// member function of Primary_attributes
	ModifyStat(STRENGTH, strength);
	ModifyStat(LEADERSHIP, leadership);
	ModifyStat(INTELLIGENCE, intelligence);
	ModifyStat(CHARACTER, character);
	ModifyStat(ENDURANCE, endurance);
	
	// // member function of Secondary_attributes
	SetSecondaryAttributes(this->Strength(), this->Leadership(), this->Intelligence(), this->Character(), this->Endurance());
	
	m_experience_points = 0;
	m_experience_points_needed = 100;
	m_total_health+=(static_cast<unsigned int>(floor(strength * 0.35)));
	m_current_health_total = m_total_health;
	m_defense+=(static_cast<unsigned int>(floor(endurance * 0.5)));
	m_speed+=(static_cast<unsigned int>(floor(endurance * 0.5)));
}

void CPrimaryStats::LevelUp(unsigned int experience_points_granted)
{
	m_experience_points+=experience_points_granted;
	
	while(m_experience_points > m_experience_points_needed)
	{
		++m_level;
		m_experience_points-=m_experience_points_needed;

		PrintToScreenLevelUp(m_level, m_experience_points, m_experience_points_needed);
		
		m_experience_points_needed*=m_level;
	}
}

void CPrimaryStats::ReduceReputation(int amount)
{
	ReduceReputation(amount);
}

void CPrimaryStats::IncreaseReputation(int amount)
{
	IncreaseReputation(amount);
}

bool CPrimaryStats::TakeDamage(int damage) 
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

void CPrimaryStats::Heal(int heal_amount)
{
	if(static_cast<unsigned int>(m_current_health_total+heal_amount) <= m_total_health)
	{
		m_current_health_total+=heal_amount;
	}
}