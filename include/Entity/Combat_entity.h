#ifndef COMBAT_ENTITY_H
#define COMBAT_ENTITY_H

#include <string>
#include <memory>

#include "Entity/Ingame_entity.h"
#include "Primary_stats/Primary_stats.h"

class CCombatEntity: public CIngameEntityHuman
{
    public:
    // default constructor
    CCombatEntity();
    // constructor for player characters
    CCombatEntity(const std::string& name, Gender gender, Race race, Job job);
    // constructor for copy constructor, used for party characters or specific hostiles
    CCombatEntity(const CCombatEntity& old);
    // simple constructor for hostile characters
    CCombatEntity(const std::string& name, Gender gender, Race race, Job job, int difficulty);
    // constructor for specifically designed combat entites
    CCombatEntity(const std::string& name, int gender, int race, int job, bool hostile, int strength, int leadership, 
            int intelligence, int character, int endurance, unsigned int level, unsigned int total_health, 
            int current_health_total, unsigned int defense, unsigned int speed);
    ~CCombatEntity();
    
    // character creator
    void CharacterCreator();
    void PartyCharacterCreator() {}
    
    // mutator functions
    void ReduceOrIncreaseReputation(bool increase, int amount);
    
    // accessor functions
	unsigned int Level() const { return m_innate_character_stats.Level(); }
	unsigned int TotalHealth() const { return m_innate_character_stats.TotalHealth(); }
	unsigned int CurrentHealthTotal() const { return m_innate_character_stats.CurrentHealthTotal(); }
	unsigned int Speed() const { return m_innate_character_stats.Speed(); }
	unsigned int ExperiencePoints() const { return m_innate_character_stats.ExperiencePoints(); }
	unsigned int ExperiencePointsNeeded() const { return m_innate_character_stats.ExperiencePointsNeeded(); }
	int Strength() const { return m_innate_character_stats.Strength(); }
	
	// adds a comparator for comparing combat_entity's speeds
	struct SSpeedCompare
	{
		public:
		// overloads () operator for use as functor to facilitate comparing of speeds
		bool operator()(const std::shared_ptr<CCombatEntity> first, const std::shared_ptr<CCombatEntity> second) const
		{
			return first->Speed()>=second->Speed();
		}
	};
	
	// adds a comparator for comparing combat_entity's IDs
	struct SIdCompare
	{
		public:
		// overloads () operator for use as functor to facilitate comparing of IDs
		bool operator()(const std::shared_ptr<CCombatEntity> first, const std::shared_ptr<CCombatEntity> second) const
		{
			return first->ID()==second->ID();
		}
	};
    
    // combat functions
	
	// prints out the character information for combat
	virtual void PrintHeaderStats();
	
	// more extensive print out
	void PrintStats();
	
	// given a vector of potential targets prompts the user for their desired target
	int SelectTarget(const std::vector<std::shared_ptr<CCombatEntity>>& possible_targets);
	
	// checks if the entity can take its turn
	virtual bool CheckStatus() { return true; }
	
	// function to take a turn during combat, can be overloaded for deriving classes that actually
	// can be in combat. function will return true if entity took a successful action and false if
	// the entity is dead or unable to take an action
	// returns false by default if not overloaded
	virtual bool Turn(std::vector<std::shared_ptr<CCombatEntity>>& turn_order) { return true; }
	
	// calls this function when the character takes damage
	bool DamageEntity(int amount_of_damage);
    
    private:
    // declared in primary_stats.h
	CPrimaryStats m_innate_character_stats;
};

#endif