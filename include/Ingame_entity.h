/*	Copyright 2016 George Le
	Declaration of base ingame_entity classes that all ingame entities can inherit from
	
	Declarations:
		-preprocessor directives: MAX_GENDER, MAX_RACE, MAX_CLASSES
		-emumerated types: Gender, Race, Job, Alignment
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
#include <memory>

enum Gender {UNINIT , MALE, FEMALE, OTHER_ORIENTATION};
enum Race {UNSET, WHITE, BLACK, ASIAN, HISPANIC, INDIGENOUS, OTHER};
enum Job {UNEMPLOYED, MARINE, CAPTAIN, LAWYER, ARMORER, ECONOMIST, GAMBLER, REPORTER, NOMAD};

enum Alignment { NOTSET, CHAOTIC_EVIL, CHAOTIC_NEUTRAL, CHAOTIC_GOOD, NEUTRAL_EVIL, 
				TRUE_NEUTRAL, NEUTRAL_GOOD, LAWFUL_EVIL, LAWFUL_NEUTRAL, LAWFUL_GOOD };

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
	int ID() const { return m_ID; }
	std::string name() const { return m_entity_name; }
	Gender gender() const { return m_entity_gender; }
	Race race() const { return m_entity_race; }
	Job job() const { return m_entity_class; }
	
	// special accessor functions that return strings instead of an enumerated type
	std::string get_gender_as_string() const;
	std::string get_race_as_string() const;
	std::string get_job_as_string() const;
	
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
	
	// determines some of the bonuses that player gains by immersing themselves into
	// their character's selected alignment
	int m_character_ethics;
	
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