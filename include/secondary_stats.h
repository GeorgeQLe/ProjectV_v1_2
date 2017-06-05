#ifndef SECONDARY_STATS_H
#define SECONDARY_STATS_H

#include <string>

//defunct-commented just in case
// enum Type_of_secondary_stats { KNOWLEDGE_BASED_STATS = 1, ACTIONS_BASED_STATS, STATURE_BASED_STATS, INTERACTION_BASED_STATS};
// enum Type_of_knowledge_based_stats { WISDOM_STAT = 1, HISTORY_KNOWLEDGE_STAT, MEDICAL_KNOWLEDGE_STAT, FAUNA_KNOWLEDGE_STAT,
//                                     COMMON_SENSE_STAT, LANGUAGE_SKILL_STAT};
// enum Type_of_action_based_stats { ATHLETICS_STAT = 1, DEXTERITY_STAT, SLEIGHT_OF_HAND_STAT, STEALTH_SKILL_STAT, LOCKPICKING_STAT,
//                                     HACKING_STAT};
// enum Type_of_stature_based_stats { INTIMIDATION_STAT = 1, HEAT_RESISTANCE, COLD_RESISTANCE};                                    
// enum Type_of_interaction_based_stats { PERSUASION_STAT = 1, BARTER_STAT, EDUCATION_STAT, FAITH_STAT, XENOPHOBIA_STAT, ANIMAL_HANDLING_STAT};

class Secondary_stats
{
    public:
    Secondary_stats() : wisdom(1), history_knowledge(1), medical_knowledge(1), fauna_knowledge(1), common_sense(1), 
                        language_skill(1), athletics(1), dexterity(1), sleight_of_hand(1), stealth_skill(1), 
                        lockpicking(1), hacking(1), intimidation(1), heat_resistance(1), cold_resistance(1),
                        persuasion(1), barter(1), education(1), faith(1), xenophobia(1), animal_handling(1) {}
    Secondary_stats(unsigned int wisdom, unsigned int history_knowledge, unsigned int medical_knowledge,
                            unsigned int fauna_knowledge, unsigned int common_sense, unsigned int language_skill,
                            unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand,
                            unsigned int stealth_skill, unsigned int lockpicking, unsigned int hacking, 
                            unsigned int intimidation, unsigned int heat_resistance, unsigned int cold_resistance,
                            unsigned int persuasion, unsigned int barter, unsigned int education,
                            unsigned int faith, unsigned int xenophobia, unsigned int animal_handling) : wisdom(wisdom),
                            history_knowledge(history_knowledge), medical_knowledge(medical_knowledge),
                            fauna_knowledge(fauna_knowledge), common_sense(common_sense), language_skill(language_skill),
                            athletics(athletics), dexterity(dexterity), sleight_of_hand(sleight_of_hand),
                            stealth_skill(stealth_skill), lockpicking(lockpicking), hacking(hacking), 
                            intimidation(intimidation), heat_resistance(heat_resistance), cold_resistance(cold_resistance),
                            persuasion(persuasion), barter(barter), education(education), faith(faith), 
                            xenophobia(xenophobia), animal_handling(animal_handling) {}
                            
    bool check_stat(unsigned int& your_stat, unsigned int difficulty_check);
    
    //knowledge based secondary stats
    unsigned int wisdom, history_knowledge, medical_knowledge, fauna_knowledge, common_sense, language_skill;
    //action based secondary stats
    unsigned int athletics, dexterity, sleight_of_hand, stealth_skill, lockpicking, hacking;
    //stature based secondary stats
    unsigned int intimidation, heat_resistance, cold_resistance;
    //interaction based secondary stats
    unsigned int persuasion, barter, education, faith, xenophobia, animal_handling;
};

class Secondary_stats_initializer
{
    public:
    Secondary_stats_initializer(const std::string& script_name) : custom_creation_script(script_name) {}  
    
    void init_secondary_stats_non_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum);
    void init_secondary_stats_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum);
    void on_Read(const std::string& Event_name);
    
    void scenes_Marine_custom(Secondary_stats& stats_to_be_init);
    void scenes_Naval_captain_custom(Secondary_stats& stats_to_be_init);
    void scenes_Lawyer_custom(Secondary_stats& stats_to_be_init);
    void scenes_Armorer_custom(Secondary_stats& stats_to_be_init);
    void scenes_Economist_custom(Secondary_stats& stats_to_be_init);
    
    std::string custom_creation_script;
};
#endif