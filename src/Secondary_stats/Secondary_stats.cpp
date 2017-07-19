/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats class
*/
#include <iostream>
#include "Secondary_stats/Secondary_stats.h"
#include "Support/support.h"

Secondary_stats::Secondary_stats()
{
    // Empty constructor other than initializer list
}

Secondary_stats::Secondary_stats(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand, unsigned int stealth_skill, 
                    unsigned int lockpicking, unsigned int hacking, unsigned int persuasion, unsigned int barter, unsigned int education,
                    unsigned int faith, unsigned int xenophobia, unsigned int animal_handling, unsigned int wisdom,
                    unsigned int history_knowledge, unsigned int medicine_knowledge, unsigned int surgery_knowledge, 
                    unsigned int fauna_knowledge, unsigned int common_sense, unsigned int language_skill, 
                    unsigned int intimidation, unsigned int heat_resistance, unsigned int cold_resistance)
                    : Secondary_stats_action(athletics, dexterity, sleight_of_hand, stealth_skill, lockpicking, hacking),
                    Secondary_stats_interaction(persuasion, barter, education, faith, xenophobia, animal_handling),
                    Secondary_stats_knowledge(wisdom, history_knowledge, medicine_knowledge, surgery_knowledge, fauna_knowledge,
                    common_sense, language_skill), 
                    Secondary_stats_stature(intimidation, heat_resistance, cold_resistance)
{
    // Empty constructor other than initializer list
}

Secondary_stats::Secondary_stats(Secondary_stats& old) 
        : Secondary_stats_action(old.athletics(), old.dexterity(), old.sleight_of_hand(), old.stealth(), old.lockpicking(),
                                old.hacking()),
        Secondary_stats_interaction(old.persuasion(), old.barter(), old.education(), old.faith(), old.xenophobia(), 
                                old.animal_handling()),
        Secondary_stats_knowledge(old.wisdom(), old.history_knowledge(), old.medicine_knowledge(), old.surgery_knowledge(),
                                old.fauna_knowledge(), old.common_sense(), old.language_skill()),
        Secondary_stats_stature(old.intimidation(), old.heat_resistance(), old.cold_resistance())
{
    // Empty constructor other than initializer list
}