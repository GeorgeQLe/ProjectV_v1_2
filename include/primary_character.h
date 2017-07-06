/*	Copyright 2017 George Le
	Declares the derived classes of ingame_entity_human
	
	Declaration:
		-enums Alignment, Change_stat
		-classes
			-Primary_character->derived from ingame_entity_human
*/

#ifndef PRIMARY_CHARACTER_H
#define PRIMARY_CHARACTER_H

#include "ingame_entity.h"
#include "primary_stats.h"
#include "secondary_stats.h"
#include "actions.h"

enum Alignment { NOTSET, CHAOTIC_EVIL, CHAOTIC_NEUTRAL, CHAOTIC_GOOD, NEUTRAL_EVIL, 
				TRUE_NEUTRAL, NEUTRAL_GOOD, LAWFUL_EVIL, LAWFUL_NEUTRAL, LAWFUL_GOOD };
enum Change_stat { REDUCE, INCREASE };

class Primary_character : public Ingame_entity_human
{
	public:
	Primary_character(bool f_player);
	
	// functions used to undergo character creation for the player
	void character_creator();
	void party_character_creator();
	
	// controlled mutator function
	void reduce_or_increase_reputation(Change_stat f_reduce_or_increase, int f_amount);
	
	// accessor functions
	unsigned int level() const;
	unsigned int total_health() const;
	unsigned int current_health_total() const;
	unsigned int speed() const;
	
	// prints stats for combat
	void print_header_stats();
	// print full list of major stats
	void print_stats();
	
	// function called once per turn of combat
	bool turn(std::vector<Ingame_entity_human*>& turn_order);
	
	// calls this function during an attack to recieve
	// the damage of the selected attack
	void attack(std::vector<Ingame_entity_human*>& turn_order);

	private:
	// declared in primary_stats.h
	Primary_stats m_innate_character_stats;
	// declared in secondary_stats.h
	Secondary_stats m_learned_character_stats;
	// determines some of the bonuses that player gains by immersing themselves into
	// their character's selected alignment
	Alignment m_character_ethics;
	// declared in actions.h
	Actions m_possible_actions;
	// declared in attacks.h
	List_of_attacks m_character_possible_attacks;
	// is this primary_character the player character or a party member?
	bool m_player_character;
};

#endif