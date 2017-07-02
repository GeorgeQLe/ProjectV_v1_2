/*	Copyright 2016 George Le
	Primary stats have two components primary and secondary attributes.
	Secondary attributes are split into five different classes for each of the attributes.
*/
#ifndef PRIMARY_STATS_H
#define PRIMARY_STATS_H

enum Primary_attribute { NONE, STRENGTH, LEADERSHIP, INTELLIGENCE, CHARACTER, ENDURANCE};

class Primary_attributes
{
	public:
	Primary_attributes() : m_strength(1), m_leadership(1), m_intelligence(1), m_character(1), m_endurance(1) {}
	Primary_attributes(int strength, int leadership, int intelligence, int character, int endurance) :
						m_strength{strength}, m_leadership{leadership}, m_intelligence{intelligence}, 
						m_character{character}, m_endurance{endurance} {}
	
	//bounds check mutator function
	void modify_stat(Primary_attribute to_be_Modified, int new_value);
	
	int strength() const { return m_strength; }
	int leadership() const { return m_leadership; }
	int intelligence() const { return m_intelligence; }
	int character() const { return m_character; }
	int endurance() const { return m_endurance; }
	
	//private:
	int m_strength;
	int m_leadership;
	int m_intelligence;
	int m_character;
	int m_endurance;
};

class Secondary_attributes_strength_based
{
	public:
	Secondary_attributes_strength_based() : m_health_modifier(1), m_attack_modifier(1), m_base_carry_limit(10),
											m_current_carry_amount(0) {}
	Secondary_attributes_strength_based(int health_modifier, int attack_modifier, unsigned int base_carry_limit, 
										unsigned int current_carry_amount) :
										m_health_modifier{health_modifier}, m_attack_modifier{attack_modifier}, m_base_carry_limit{base_carry_limit},
										m_current_carry_amount{current_carry_amount} {}
	
	void calculate_strength_based_attributes(int strength);
	
	//psuedo-mutator functionsvoid 
	//strength based attribute mutators
	void calculate_health_modifier(int strength);
	void calculate_attack_modifier(int strength);
	void calculate_base_carry_amount(int strength);
	bool set_current_carry_amount(unsigned int new_carry_amount);
	
	//accessor functions
	unsigned int base_carry_limit() const { return m_base_carry_limit; }
	unsigned int current_carry_amount() const { return m_current_carry_amount; }
	
	protected:
	//strength - big angry bang bang pick things up put things down
	//strength related variables
	int m_health_modifier; //double? also not unsigned bc you can have a negative modifier(thanks DnD)
	int m_attack_modifier;
	unsigned int m_base_carry_limit; //unsigned bc why would you have negative carry capacity?
	unsigned int m_current_carry_amount;
};

class Secondary_attributes_leadership_based
{
	public:
	Secondary_attributes_leadership_based() : m_friendly_morale_modifier(1), m_strategy_stat(1), 
											m_tactical_stat(1), m_nerves(1) {}
	Secondary_attributes_leadership_based(int friendly_morale_modifier, int strategy_stat, 
										int tactical_stat, unsigned int nerves) : 
										m_friendly_morale_modifier{friendly_morale_modifier}, m_strategy_stat{strategy_stat},
										m_tactical_stat{tactical_stat}, m_nerves{nerves} {}
	
	void calculate_leadership_based_attributes(int leadership);
	
	//accessor functions
	int friendly_morale() const { return m_friendly_morale_modifier; }
	int strategy_stat() const { return m_strategy_stat; }
	int tactical_stat() const { return m_tactical_stat; }
	unsigned int nerves() const { return m_nerves; }
	
	//psuedo-mutator functionsvoid 
	//leadership based attribute mutators
	void calculate_friendly_morale_modifier(int leadership);
	void calculate_strategy_stat(int leadership);
	void calculate_tactical_stat(int leadership);
	void calculate_nerves_stat(int leadership);
	
	protected:
	//leadership stat with two general paths though both can be utilized
    //morale and strategy both bolster general-style play 
    //tactical and morale to a minor extent bolster squad to individual play
    //stat for the effect player has on friendly troops (inspire)
    //also includes your morale and cunning
	int m_friendly_morale_modifier;
	int m_strategy_stat;
	int m_tactical_stat;
	unsigned int m_nerves;
};

class Secondary_attributes_intelligence_based
{
	public:
	Secondary_attributes_intelligence_based() : m_sciences_stat(1), m_social_sciences_stat(1),
												m_tinkering_stat(1), m_tech_savvy_stat(1) {}
	Secondary_attributes_intelligence_based(int sciences_stat, int social_sciences_stat, 
											int tinkering_stat, int tech_savvy_stat) : 
											m_sciences_stat{sciences_stat}, m_social_sciences_stat{social_sciences_stat}, 
											m_tinkering_stat{tinkering_stat}, m_tech_savvy_stat{tech_savvy_stat} {}
	
	void calculate_intelligence_based_attributes(int intelligence);
	
	//intelligence based attribute mutators
	void calculate_science_stat(int leadership);
	void calculate_social_sciences_stat(int leadership);
	void calculate_tinkering_stat(int leadership);
	void calculate_tech_savvy_stat(int leadership);
	
	//accessor functions
	int science_stat() const { return m_sciences_stat; }
	int social_science_stat() const { return m_social_sciences_stat; }
	int tinkering_stat() const { return m_tinkering_stat; }
	int tech_stat() const { return m_tech_savvy_stat; }
	
	protected:
	//intelligence affects the ability for the player to perform a certain function
    //though lower intelligence is perhaps not a bad thing due to the lack of 
    //potential of overthinking things
    //intelligence has three major areas that affect leadership and character
    //science affects the player's ability to perform abilities based on science,
    //medicine, mathematics, engineering, and computers.
	int m_sciences_stat;
	int m_social_sciences_stat;
	int m_tinkering_stat;
	int m_tech_savvy_stat;
};

class Secondary_attributes_character_based
{
	public:
	Secondary_attributes_character_based() : m_suave(0), m_reputation(0), m_presence(0), m_deception(1) {}
	Secondary_attributes_character_based(int suave, int reputation, int presence, 
										unsigned int deception) : m_suave{suave}, m_reputation{reputation},
										m_presence{presence}, m_deception{deception} {}
	
	void calculate_character_based_attributes(int character);
	
	//accessor functions
	int suave() const { return m_suave; }
	int reputation() const { return m_reputation; }
	int presence() const { return m_presence; }
	unsigned int deception() const { return m_deception; }
	
	//character based attribute mutators
	void calculate_suave_stat(int character);
	void calculate_reputation_stat(int character);
	void calculate_presence_stat(int character);
	void calculate_deception_stat(int character);
	
	void reduce_reputation(int amount);
	void increase_reputation(int amount);
	
	protected:
	//character affects the ability for the player to either positively or negatively affect 
    //the gamespace around them (environment, NPCs), interactions with advisors, general NPC conversations,
    //and diplomacy, and initial reputation to unmet NPCs and factions.
    int m_suave;
    int m_reputation;
    int m_presence; 
    unsigned int m_deception;
};

class Secondary_attributes_endurance_based
{
	public:
	Secondary_attributes_endurance_based() : m_stamina(10), m_health_regeneration(1), m_speed_modifier(1), m_armor_resistance(1) {}
	Secondary_attributes_endurance_based(unsigned int stamina, unsigned int health_regeneration, 
										unsigned int speed_modifier, unsigned int armor_resistance) :
										m_stamina{stamina}, m_health_regeneration{health_regeneration}, 
										m_speed_modifier{speed_modifier}, m_armor_resistance{armor_resistance} {}
	
	void calculate_endurance_based_attributes(int endurance);
	
	//accessor functions
	unsigned int get_stamina() const { return m_stamina; }
	unsigned int get_armor_resistance() const { return m_armor_resistance; }
	
	//endurance based attribute mutators
	void calculate_stamina_stat(int endurance);
	void calculate_health_regeneration_stat(int endurance);
	void calculate_speed_modifier_stat(int endurance);
	void calculate_armor_resistance(int endurance);
	protected:
	//endurance affects the ability for the player to perform actions, survive long term
    //engagements, and the rate at which players take actions. 
    //Potential addition: fatigue in travels
    unsigned int m_stamina;
    unsigned int m_health_regeneration;
    unsigned int m_speed_modifier;
    unsigned int m_armor_resistance; //modified by gear
};

class Secondary_attributes : protected Secondary_attributes_strength_based, protected Secondary_attributes_leadership_based,
							protected Secondary_attributes_intelligence_based, protected Secondary_attributes_character_based,
							protected Secondary_attributes_endurance_based
				
{
	public:
	Secondary_attributes() {}
	
	void set_secondary_attributes(const Primary_attributes& primary_stat_modifiers); //character creation
	void update_stats(const Primary_attributes& changed_stats); //level up
	
	void reduce_reputation(int amount);
	void increase_reputation(int amount);
};

class Primary_stats
{
	public:
	Primary_stats() : m_stat_modifiers(), m_supporting_stat_modifiers(), m_level(1), 
					m_experience_points(0), m_experience_points_needed(100), m_total_health(10), 
					m_current_health_total(10), m_defense(0), m_speed(1) {}
	Primary_stats(int preset_strength, int preset_leadership, int preset_intelligence, int preset_character,
					int preset_endurance, int preset_level, unsigned int preset_total_health, int current_health_total,
					unsigned int defense, unsigned int speed);
	void init_primary_stats(int strength, int leadership, int intelligence, int character, int endurance);
	void modify_stat(Primary_attribute to_be_modified, int level);
	void level_up(unsigned int experience_points_granted);
	
	//accessor functions
	unsigned int level() const { return m_level; }
	unsigned int experience_points() const { return m_experience_points; }
	unsigned int experience_points_needed() const { return m_experience_points_needed; }
	unsigned int total_health() const { return m_total_health; }
	unsigned int current_health_total() const { return m_current_health_total; }
	unsigned int defense() const { return m_defense; }
	unsigned int speed() const { return m_speed; }
	
	int strength() const { return m_stat_modifiers.strength(); }
	int leadership() const { return m_stat_modifiers.leadership(); }
	int intelligence() const { return m_stat_modifiers.intelligence(); }
	int character() const { return m_stat_modifiers.character(); }
	int endurance() const { return m_stat_modifiers.endurance(); }
	
	void reduce_reputation(int amount);
	void increase_reputation(int amount);

	private:
	Primary_attributes m_stat_modifiers;
	Secondary_attributes m_supporting_stat_modifiers;
	
	//general stats
	unsigned int m_level;
	unsigned int m_experience_points;
	unsigned int m_experience_points_needed;
	
	//health related variables
	unsigned int m_total_health;
	int m_current_health_total; // not unsigned bc it can be negative much to the player's chagrin
	unsigned int m_defense;
	unsigned int m_speed;
};

#endif