/*	Copyright 2017 George Le
	Declaration of the Primary_character class and its member function
*/

#ifndef PRIMARY_CHARACTER_H
#define PRIMARY_CHARACTER_H

#include <memory>

#include "Actions/Actions.h"
#include "Attacks/List_of_attacks.h"
#include "Entity/Combat_entity.h"
#include "Secondary_stats/Secondary_stats.h"

class Primary_character : public Combat_entity
{
	public:
	Primary_character(bool player);
	~Primary_character() {}
	
	// function used to undergo secondary stat creation for the player
	void character_creator();
	// function used for creating secondary stat creation for player-allied characters
	void party_character_creator() {}
	
	bool equip_weapons();
	
	// controlled mutator function
	void reduce_or_increase_reputation(bool increase, int amount);
	
	// function called once per turn of combat
	// return true if the character was able to successfully complete a turn
	// else return false if for some reason the player couldn't take their turn
	bool turn(std::vector<std::shared_ptr<Combat_entity>>& turn_order);
	
	// function to called to let the character choose an offensive action
	// returns true if the character selects an action, returns false if the
	// character wants to return to the previous prompt
	bool action(std::vector<std::shared_ptr<Combat_entity>>& turn_order);
	
	// calls this function to attack
	bool attack(std::shared_ptr<Combat_entity> target);
	
	// calls this function to perform an ultimate attack
	bool ultimate_attacks(std::shared_ptr<Combat_entity> target);

	// calls this function to use an item
	bool items(std::shared_ptr<Combat_entity> target);
	
	// calls this function to move
	bool move() { return true; }
	
	private:
	// declared in secondary_stats.h
	Secondary_stats m_learned_character_stats;
	
	// declared in actions.h
	Actions m_possible_actions;
	// declared in attacks.h
	List_of_attacks m_character_possible_attacks;
	
	// is this primary_character the player character or a party member?
	bool m_player_character;
};

#endif