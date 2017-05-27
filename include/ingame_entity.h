/*	Copyright 2016 George Le
	
*/
#ifndef INGAME_ENTITY_H
#define INGAME_ENTITY_H

#include <string>

enum Gender {UNINIT , MALE, FEMALE, OTHER_ORIENTATION};
enum Race {UNSET, WHITE, BLACK, ASIAN, HISPANIC, INDIGENOUS, OTHER};
enum Job {UNEMPLOYED, MARINE, CAPTAIN, LAWYER, ARMORER, ECONOMIST, GAMBLER, REPORTER, NOMAD};

//valid for all ingame entities: Playable/controllable, NPCs	
class Ingame_entity_human
{
	public:
	Ingame_entity_human() : m_entity_name("Default name"), m_entity_gender(UNINIT), m_entity_race(UNSET), m_entity_class(UNEMPLOYED) {}
	Ingame_entity_human(const std::string& name, Gender gender, Race race, Job job) : m_entity_name(name), m_entity_gender(gender),
																			m_entity_race(race), m_entity_class(job) {}
									
	std::string get_name() const { return m_entity_name; }
	Gender get_gender() const { return m_entity_gender; }
	Race get_race() const { return m_entity_race; }
	Job get_job() const { return m_entity_class; }
	std::string get_gender_as_string() const;
	std::string get_race_as_string() const;
	std::string get_job_as_string() const;
	
	protected:
	void set_information();
	
	private:
	void set_name(const std::string& name) { m_entity_name = name; }
	void set_gender(int gender) { m_entity_gender = static_cast<Gender>(gender); }
	void set_race(int race) { m_entity_race = static_cast<Race>(race); }
	void set_job(int job) { m_entity_class = static_cast<Job>(job); }
	
	std::string m_entity_name;
	Gender m_entity_gender;
	Race m_entity_race;
	Job m_entity_class;
};

//just leaving this here for now... too early to fully implement
class Ingame_entity_vehicle
{
	public:
	Ingame_entity_vehicle() : m_entity_name("Default name") {}
	Ingame_entity_vehicle(std::string name) : m_entity_name(name) {}
	
	private:
	void set_name(std::string name) { m_entity_name = name; }
	
	std::string m_entity_name;
};

#endif