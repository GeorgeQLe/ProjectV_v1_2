/*  Copyright 2017 George Le
    Declaration of the Secondary_stats class and its member functions
*/
#ifndef SECONDARY_STATS_H
#define SECONDARY_STATS_H

#include <string>

#include "Secondary_stats/Secondary_stats_action.h"
#include "Secondary_stats/Secondary_stats_interaction.h"
#include "Secondary_stats/Secondary_stats_knowledge.h"
#include "Secondary_stats/Secondary_stats_stature.h"

class Secondary_stats : public Secondary_stats_action, public Secondary_stats_interaction,
                        public Secondary_stats_knowledge, public Secondary_stats_stature
{
    public:
    Secondary_stats();
    Secondary_stats(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand, unsigned int stealth_skill, 
                    unsigned int lockpicking, unsigned int hacking, unsigned int persuasion, unsigned int barter, unsigned int education,
                    unsigned int faith, unsigned int xenophobia, unsigned int animal_handling, unsigned int wisdom,
                    unsigned int history_knowledge, unsigned int medicine_knowledge, unsigned int surgery_knowledge, 
                    unsigned int fauna_knowledge, unsigned int common_sense, unsigned int language_skill, unsigned int intimidation, 
                    unsigned int heat_resistance, unsigned int cold_resistance);
    Secondary_stats(Secondary_stats& old);
};

#endif