/*	Copyright 2016 George Le
	definitions of the member functions for the classes in primary_stats.h
*/
#include <iostream>
#include <cmath>
#include "Primary_stats.h"

// function only to be used in leveling up
void print_to_screen_level_up(unsigned int current_level, unsigned int experience_points, 
							  unsigned int experience_points_needed);

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

// function for setting up and updating stength based secondary attributes
void Secondary_attributes_strength_based::calculate_strength_based_attributes(int strength)
{
	calculate_health_modifier(strength);
	calculate_attack_modifier(strength);
	calculate_base_carry_amount(strength);
	set_current_carry_amount(0);
}

// function for setting up and updating leadership based secondary attributes
void Secondary_attributes_leadership_based::calculate_leadership_based_attributes(int leadership)
{
	calculate_friendly_morale_modifier(leadership);
	calculate_strategy_stat(leadership);
	calculate_tactical_stat(leadership);
	calculate_nerves_stat(leadership);
}

// function for setting up and updating intelligence based secondary attributes
void Secondary_attributes_intelligence_based::calculate_intelligence_based_attributes(int leadership)
{
	calculate_science_stat(leadership);
	calculate_social_sciences_stat(leadership);
	calculate_tinkering_stat(leadership);
	calculate_tech_savvy_stat(leadership);
}

// function for setting up and updating character based secondary attributes
void Secondary_attributes_character_based::calculate_character_based_attributes(int character)
{
	calculate_suave_stat(character);
	calculate_reputation_stat(character);
	calculate_presence_stat(character);
	calculate_deception_stat(character);
}

// function for setting up and updating endurance based secondary attributes
void Secondary_attributes_endurance_based::calculate_endurance_based_attributes(int endurance)
{
	calculate_stamina_stat(endurance);
	calculate_health_regeneration_stat(endurance);
	calculate_speed_modifier_stat(endurance);
	calculate_armor_resistance(endurance);
}

void Secondary_attributes_strength_based::calculate_health_modifier(int strength)
{
	m_health_modifier = static_cast<int>(floor((strength * 0.4) + 1)); 
}

void Secondary_attributes_strength_based::calculate_attack_modifier(int strength)
{
	m_attack_modifier = static_cast<int>(floor((strength * 0.29) + 1));
}

void Secondary_attributes_strength_based::calculate_base_carry_amount(int strength)
{
	m_base_carry_limit = static_cast<unsigned int>(floor((strength * 0.72) + 1));
}

bool Secondary_attributes_strength_based::set_current_carry_amount(unsigned int new_carry_amount)
{
	if(new_carry_amount > 0)
	{
		if((static_cast<unsigned int>(new_carry_amount) > m_base_carry_limit))
		{
			return false;
		}
	}
	m_current_carry_amount = static_cast<unsigned int>(new_carry_amount);
	return true;
}

void Secondary_attributes_leadership_based::calculate_friendly_morale_modifier(int leadership)
{
	m_friendly_morale_modifier = static_cast<int>(floor((leadership * 0.3) + 1));
}

void Secondary_attributes_leadership_based::calculate_strategy_stat(int leadership)
{
	m_strategy_stat = static_cast<int>(floor((leadership * 0.3) + 1));	
}

void Secondary_attributes_leadership_based::calculate_tactical_stat(int leadership)
{
	m_tactical_stat = static_cast<int>(floor((leadership * 0.3) + 1));
}

void Secondary_attributes_leadership_based::calculate_nerves_stat(int leadership)
{
	m_nerves = static_cast<unsigned int>(floor((leadership * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_science_stat(int intelligence)
{
	m_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_social_sciences_stat(int intelligence)
{
	m_social_sciences_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_tinkering_stat(int intelligence)
{
	m_tinkering_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_intelligence_based::calculate_tech_savvy_stat(int intelligence)
{
	m_tech_savvy_stat = static_cast<int>(floor((intelligence * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_suave_stat(int character)
{
	m_suave = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_reputation_stat(int character)
{
	m_reputation = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_presence_stat(int character)
{
	m_presence = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::calculate_deception_stat(int character)
{
	m_deception = static_cast<int>(floor((character * 0.5) + 1));
}

void Secondary_attributes_character_based::reduce_reputation(int amount)
{
	m_reputation-=amount;
}

void Secondary_attributes_character_based::increase_reputation(int amount)
{
	m_reputation+=amount;
}

void Secondary_attributes_endurance_based::calculate_stamina_stat(int endurance)
{
	m_stamina = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void Secondary_attributes_endurance_based::calculate_health_regeneration_stat(int endurance)
{
	m_health_regeneration = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void Secondary_attributes_endurance_based::calculate_speed_modifier_stat(int endurance)
{
	m_speed_modifier = static_cast<unsigned int>(floor((endurance * 0.5) + 1));	
}

void Secondary_attributes_endurance_based::calculate_armor_resistance(int endurance)
{
	m_armor_resistance = static_cast<unsigned int>(floor((endurance * 0.25) + 1));
}

void Primary_attributes::modify_stat(Primary_attribute to_be_Modified, int new_value)
{
	switch(to_be_Modified)
	{
		using std::cout;
		
		case 1:
		if(new_value > 0)
		{
			m_strength = new_value;
		}
		else
		{
			cout << "Strength can't be less than zero\n";
		}
		break;
		case 2:
		if(new_value > 0)
		{
			m_leadership = new_value;
		}
		else
		{
			cout << "Leadership can't be less than zero\n";
		}
		break;
		case 3:
		if(new_value > 0)
		{
			m_intelligence = new_value;
		}
		else
		{
			cout << "Intelligence can't be less than zero\n";
		}
		break;
		case 4:
		if(new_value > 0)
		{
			m_character = new_value;
		}
		else
		{
			cout << "Character can't be less than zero\n";
		}
		break;
		case 5:
		if(new_value > 0)
		{
			m_endurance = new_value;
		}
		else
		{
			cout << "Endurance can't be less than zero\n";
		}
		break;
		default:
		cout << "Not a valid stat\n";
		break;
	}
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

void Secondary_attributes::reduce_reputation(int amount)
{
	reduce_reputation(amount);
}

void Primary_stats::increase_reputation(int amount)
{
	increase_reputation(amount);
}

void Secondary_attributes::increase_reputation(int amount)
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

void print_to_screen_level_up(unsigned int current_level, unsigned int experience_points, unsigned int experience_points_needed)
{
	std::cout << "Congratulations, you have leveled up to level " << current_level << "!\n";
	std::cout << experience_points << "/" << experience_points_needed << std::endl;
}