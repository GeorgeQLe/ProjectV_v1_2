/*  Copyright 2017 George Le
    Declaration of the Secondary_stats class and its member functions
*/
#ifndef SECONDARY_STATS_H
#define SECONDARY_STATS_H

#include <string>

#include "Secondary_stats/Secondary_stats_knowledge.h"

class Secondary_stats
{
    public:
    Secondary_stats() : m_athletics(1), m_dexterity(1), m_sleight_of_hand(1), m_stealth_skill(1), 
                        m_lockpicking(1), m_hacking(1), m_intimidation(1), m_heat_resistance(1), m_cold_resistance(1),
                        m_persuasion(1), m_barter(1), m_education(1), m_faith(1), m_xenophobia(1), m_animal_handling(1) {}
    Secondary_stats(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand,
                            unsigned int stealth_skill, unsigned int lockpicking, unsigned int hacking, 
                            unsigned int intimidation, unsigned int heat_resistance, unsigned int cold_resistance,
                            unsigned int persuasion, unsigned int barter, unsigned int education,
                            unsigned int faith, unsigned int xenophobia, unsigned int animal_handling) :
                            m_athletics(athletics), m_dexterity(dexterity), m_sleight_of_hand(sleight_of_hand),
                            m_stealth_skill(stealth_skill), m_lockpicking(lockpicking), m_hacking(hacking), 
                            m_intimidation(intimidation), m_heat_resistance(heat_resistance), m_cold_resistance(cold_resistance),
                            m_persuasion(persuasion), m_barter(barter), m_education(education), m_faith(faith), 
                            m_xenophobia(xenophobia), m_animal_handling(animal_handling) {}
                            
    bool check_stat(unsigned int& your_stat, unsigned int difficulty_check);
    
    private:
    //action based secondary stats
    unsigned int m_athletics, m_dexterity, m_sleight_of_hand, m_stealth_skill, m_lockpicking, m_hacking;
    //stature based secondary stats
    unsigned int m_intimidation, m_heat_resistance, m_cold_resistance;
    //interaction based secondary stats
    unsigned int m_persuasion, m_barter, m_education, m_faith, m_xenophobia, m_animal_handling;
};

#endif