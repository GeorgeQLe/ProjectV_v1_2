#ifndef PRIMARY_CHARACTER_H
#define PRIMARY_CHARACTER_H

#include "ingame_entity.h"
#include "primary_stats.h"
#include "secondary_stats.h"

enum Alignment { NOTSET, CHAOTIC_EVIL, CHAOTIC_NEUTRAL, CHAOTIC_GOOD, NEUTRAL_EVIL, 
				TRUE_NEUTRAL, NEUTRAL_GOOD, LAWFUL_EVIL, LAWFUL_NEUTRAL, LAWFUL_GOOD };

enum Reputation_change { REDUCE, INCREASE };

class Primary_character : public Ingame_entity_human
{
	public:
	Primary_character();
	
	void character_creator();
	void reduce_or_increase_reputation(const Reputation_change& reduce_or_increase, int amount);

	private:
	std::string script_name;
	
	Primary_stats innate_character_stats;
	Secondary_stats learned_character_stats;
	Alignment character_ethics;
};

#endif