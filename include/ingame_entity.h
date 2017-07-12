/*	Copyright 2016 George Le
	Declaration of base ingame_entity classes that all ingame entities can inherit from
	
	Declarations:
		-preprocessor directives: MAX_GENDER, MAX_RACE, MAX_CLASSES
		-emumerated types: Gender, Race, Job 
		Classes:
			-Ingame_entity_human
			-Ingame_entity_vehicle
*/
#ifndef INGAME_ENTITY_H
#define INGAME_ENTITY_H

#define MAX_GENDER 3
#define MAX_RACE 6
#define MAX_CLASSES 8
#include <string>
#include <vector>

enum Gender {UNINIT , MALE, FEMALE, OTHER_ORIENTATION};
enum Race {UNSET, WHITE, BLACK, ASIAN, HISPANIC, INDIGENOUS, OTHER};
enum Job {UNEMPLOYED, MARINE, CAPTAIN, LAWYER, ARMORER, ECONOMIST, GAMBLER, REPORTER, NOMAD};

//valid for all ingame entities: Playable/controllable, NPCs	
class Ingame_entity_human
{
	public:
	// default constructor
	Ingame_entity_human() : m_entity_name("Default name"), m_entity_gender(UNINIT), m_entity_race(UNSET), m_entity_class(UNEMPLOYED) {}
	Ingame_entity_human(const std::string& name, Gender gender, Race race, Job job, bool is_hostile) : m_is_hostile(is_hostile), 
						m_entity_name(name), m_entity_gender(gender), m_entity_race(race), m_entity_class(job) {}
	// special version of previous constructor to allow for ints to be passed in for gender, race , class
	// checks if ints are possible
	Ingame_entity_human(const std::string& name, int gender, int race, int job, bool is_hostile);
	virtual ~Ingame_entity_human() {}
	
	// accessor function
	bool is_hostile() const { return m_is_hostile; }
	std::string name() const { return m_entity_name; }
	Gender gender() const { return m_entity_gender; }
	Race race() const { return m_entity_race; }
	Job job() const { return m_entity_class; }
	
	// combat functions
	virtual void print_header_stats() = 0;
	
	// given a vector of potential targets prompts the user for their desired target
	int select_target(const std::vector<Ingame_entity_human*>& possible_targets);
	
	// polymorphic accessor function used to group and compare primary_characters and hostiles together in the 
	// combat turn order
	virtual unsigned int speed() const = 0;
	
	// adds a comparator for comparing ingame_entity's speeds
	struct speed_compare
	{
		public:
		// overloads () operator for use as functor to facilitate comparing of speeds
		bool operator()(const Ingame_entity_human* first, const Ingame_entity_human* second) const
		{
			return first->speed()<=second->speed();
		}
	};
	
	// special accessor functions that return strings instead of an enumerated type
	std::string get_gender_as_string() const;
	std::string get_race_as_string() const;
	std::string get_job_as_string() const;
	
	// function to take a turn during combat, can be overloaded for deriving classes that actually
	// can be in combat. function will return true if entity took a successful action and false if
	// the entity is dead or unable to take an action
	// returns false by default if not overloaded
	virtual bool turn(std::vector<Ingame_entity_human*>& turn_order) { return true; }
	
	// function to damage the character, needs to be overloaded
	virtual bool damage_entity(int amount_of_damage) = 0;
	
	protected:
	// to be used in inheriting class's constructor to set up basic information of the character
	void set_information();
	
	private:
	// private mutator functions for the special constructor
	// should not be used outside of the constructor
	void set_name(const std::string& name) { m_entity_name = name; }
	void set_gender(int gender) { m_entity_gender = static_cast<Gender>(gender); }
	void set_race(int race) { m_entity_race = static_cast<Race>(race); }
	void set_job(int job) { m_entity_class = static_cast<Job>(job); }
	
	// identifier to see if hostile or not
	bool m_is_hostile;
	
	// identifying number for the ingame_entity
	int m_ID;
	static unsigned int s_next_valid_ID;
	
	// used only in constructor to 
	void set_ID();
	
	// ingame_entitys have one std::string object and three enums
	std::string m_entity_name;
	Gender m_entity_gender;
	Race m_entity_race;
	Job m_entity_class;
};

// just leaving this here for now... too early to fully implement
// just copied the basic elements from ingame_entity_human above
class Ingame_entity_vehicle
{
	public:
	Ingame_entity_vehicle() : m_entity_name("Default name") {}
	Ingame_entity_vehicle(std::string name) : m_entity_name(name) {}
	
	private:
	void set_name(std::string name) { m_entity_name = name; }
	
	std::string m_entity_name;
};

#endif // ingame_entity.h