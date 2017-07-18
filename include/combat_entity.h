#ifndef COMBAT_ENTITY_H
#define COMBAT_ENTITY_H

#include <string>
#include <memory>
#include "ingame_entity.h"
#include "primary_stats.h"
#include "grid.h"

class Combat_entity: public Ingame_entity_human
{
    public:
    // default constructor
    Combat_entity() : Ingame_entity_human("Dummy", 1, 1, 1, false), m_innate_character_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) {}
    // constructor for player characters
    Combat_entity(const std::string& name, Gender gender, Race race, Job job);
    // constructor for copy constructor, used for party characters or specific hostiles
    Combat_entity(const Combat_entity& old);
    // simple constructor for hostile characters
    Combat_entity(const std::string& name, Gender gender, Race race, Job job, int difficulty) : Ingame_entity_human(name, gender, race, job, true),
    			m_innate_character_stats(difficulty, 1, 10, 10, 0, 1) {}
    // constructor for specifically designed combat entites
    Combat_entity(std::string name, int gender, int race, int job, bool hostile, int strength, int leadership, 
            int intelligence, int character, int endurance, unsigned int level, unsigned int total_health, 
            int current_health_total, unsigned int defense, unsigned int speed) : Ingame_entity_human(name, gender, race, job, hostile),
            m_innate_character_stats(strength, leadership, intelligence, character, endurance, level, total_health, current_health_total, defense, speed) {}
    
    // character creator
    void character_creator();
    void party_character_creator() {}
    
    // mutator functions
    void reduce_or_increase_reputation(bool increase, int amount);
    
    // function to recieve a reference to the Grid that the entity will fight on
    void set_grid(std::shared_ptr<Grid<Combat_entity>> location) { m_reference_to_location = location; }
    
    // accessor functions
	unsigned int level() const { return m_innate_character_stats.level(); }
	unsigned int total_health() const { return m_innate_character_stats.total_health(); }
	unsigned int current_health_total() const { return m_innate_character_stats.current_health_total(); }
	unsigned int speed() const { return m_innate_character_stats.speed(); }
	unsigned int experience_points() const { return m_innate_character_stats.experience_points(); }
	unsigned int experience_points_needed() const { return m_innate_character_stats.experience_points_needed(); }
	int strength() const { return m_innate_character_stats.strength(); }
	
	// adds a comparator for comparing combat_entity's speeds
	struct speed_compare
	{
		public:
		// overloads () operator for use as functor to facilitate comparing of speeds
		bool operator()(const std::shared_ptr<Combat_entity> first, const std::shared_ptr<Combat_entity> second) const
		{
			return first->speed()>=second->speed();
		}
	};
	
	// adds a comparator for comparing combat_entity's IDs
	struct ID_compare
	{
		public:
		// overloads () operator for use as functor to facilitate comparing of IDs
		bool operator()(const std::shared_ptr<Combat_entity> first, const std::shared_ptr<Combat_entity> second) const
		{
			return first->ID()==second->ID();
		}
	};
    
    // combat functions
	
	// prints out the character information for combat
	virtual void print_header_stats();
	
	// more extensive print out
	void print_stats();
	
	// given a vector of potential targets prompts the user for their desired target
	int select_target(const std::vector<std::shared_ptr<Combat_entity>>& possible_targets);
	
	// checks if the entity can take its turn
	virtual bool check_status() { return true; }
	
	// function to take a turn during combat, can be overloaded for deriving classes that actually
	// can be in combat. function will return true if entity took a successful action and false if
	// the entity is dead or unable to take an action
	// returns false by default if not overloaded
	virtual bool turn(std::vector<std::shared_ptr<Combat_entity>>& turn_order) { return true; }
	
	// calls this function when the character takes damage
	bool damage_entity(int amount_of_damage);
    
    // returns the combat_entity's grid square
    std::shared_ptr<Grid<Combat_entity>> location() { return m_reference_to_location.lock(); }
    
    private:
    // declared in primary_stats.h
	Primary_stats m_innate_character_stats;
	
	// weak pointer to the entity's location on the combat map
	// Grid_square declared in grid.h
	std::weak_ptr<Grid<Combat_entity>> m_reference_to_location;
};

#endif