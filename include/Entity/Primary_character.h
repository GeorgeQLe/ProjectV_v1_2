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

class CPrimaryCharacter : public CCombatEntity
{
	public:
	CPrimaryCharacter(bool player);
	~CPrimaryCharacter() {}
	
	// function used to undergo secondary stat creation for the player
	void CharacterCreator();
	// function used for creating secondary stat creation for player-allied characters
	void PartyCharacterCreator() {}
	
	bool EquipWeapons();
	
	// controlled mutator function
	void ReduceOrIncreaseReputation(bool increase, int amount);
	
	// function called once per turn of combat
	// return true if the character was able to successfully complete a turn
	// else return false if for some reason the player couldn't take their turn
	bool Turn(std::vector<std::shared_ptr<CCombatEntity>>& turn_order);
	
	// function to called to let the character choose an offensive action
	// returns true if the character selects an action, returns false if the
	// character wants to return to the previous prompt
	bool Action(std::vector<std::shared_ptr<CCombatEntity>>& turn_order);
	
	// calls this function to attack
	bool Attack(std::shared_ptr<CCombatEntity> target);
	
	// calls this function to perform an ultimate attack
	bool UltimateAttacks(std::shared_ptr<CCombatEntity> target);

	// calls this function to use an item
	bool Items(std::shared_ptr<CCombatEntity> target);
	
	// calls this function to move
	bool Move() { return true; }
	
	private:
	// declared in secondary_stats.h
	CSecondaryStats m_learned_character_stats;
	
	// declared in actions.h
	CActions m_possible_actions;
	// declared in attacks.h
	SListOfAttacks m_character_possible_attacks;
	
	// is this primary_character the player character or a party member?
	bool m_player_character;
};

#endif