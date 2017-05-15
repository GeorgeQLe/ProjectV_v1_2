#ifndef PRIMARY_CHARACTER_H
#define PRIMARY_CHARACTER_H

#include "ingame_entity.h"
#include "primary_stats.h"
#include "secondary_stats.h"
#include "character_setup.h"

enum Alignment { NOTSET, CHAOTIC_EVIL, CHAOTIC_NEUTRAL, CHAOTIC_GOOD, NEUTRAL_EVIL, 
				TRUE_NEUTRAL, NEUTRAL_GOOD, LAWFUL_EVIL, LAWFUL_NEUTRAL, LAWFUL_GOOD };

enum Reputation_change { REDUCE, INCREASE }; 

class Primary_character : public Ingame_entity_human
{
	public:
	Primary_character();
	Primary_character(const std::string script_name);
	
	void get_script_name(const std::string& script_name) { this->script_name = script_name; }
	void character_creator(const std::string script_name);
	
	void reduce_or_increase_reputation(const Reputation_change& reduce_or_increase, int amount);

	private:
	std::string script_name;
	
	Primary_stats innate_character_stats;
	Secondary_stats learned_character_stats;
	Alignment character_ethics;
};

#endif