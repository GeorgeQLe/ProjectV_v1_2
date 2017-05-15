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
	Ingame_entity_human() : entity_name("Default name"), entity_gender(UNINIT), entity_race(UNSET), entity_class(UNEMPLOYED) {}
	Ingame_entity_human(const std::string& name, Gender gender, Race race, Job job) : entity_name(name), entity_gender(gender),
																			entity_race(race), entity_class(job) {}
									
	std::string get_name() const { return entity_name; }
	Gender get_gender() const { return entity_gender; }
	Race get_race() const { return entity_race; }
	Job get_job() const { return entity_class; }
	
	protected:
	void set_information();
	
	private:
	void set_name(const std::string& name) { entity_name = name; }
	void set_gender(int gender) { entity_gender = static_cast<Gender>(gender); }
	void set_race(int race) { entity_race = static_cast<Race>(race); }
	void set_job(int job) { entity_class = static_cast<Job>(job); }
	
	std::string entity_name;
	Gender entity_gender;
	Race entity_race;
	Job entity_class;
};

//just leaving this here for now... too early to fully implement
class Ingame_entity_vehicle
{
	public:
	Ingame_entity_vehicle() : entity_name("Default name") {}
	Ingame_entity_vehicle(std::string name) : entity_name(name) {}
	
	private:
	void set_name(std::string name) { entity_name = name; }
	
	std::string entity_name;
};

#endif