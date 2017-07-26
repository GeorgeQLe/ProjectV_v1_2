/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryStats class
*/
#include <iostream>
#include "Secondary_stats/Secondary_stats.h"
#include "Support/support.h"

CSecondaryStats::CSecondaryStats()
{
    // Empty constructor other than initializer list
}

CSecondaryStats::CSecondaryStats(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand, unsigned int stealth_skill, 
                    unsigned int lockpicking, unsigned int hacking, unsigned int persuasion, unsigned int barter, unsigned int education,
                    unsigned int faith, unsigned int xenophobia, unsigned int animal_handling, unsigned int wisdom,
                    unsigned int history_knowledge, unsigned int medicine_knowledge, unsigned int surgery_knowledge, 
                    unsigned int fauna_knowledge, unsigned int common_sense, unsigned int language_skill, 
                    unsigned int intimidation, unsigned int heat_resistance, unsigned int cold_resistance)
                    : CSecondaryStatsAction(athletics, dexterity, sleight_of_hand, stealth_skill, lockpicking, hacking),
                    CSecondaryStatsInteraction(persuasion, barter, education, faith, xenophobia, animal_handling),
                    CSecondaryStatsKnowledge(wisdom, history_knowledge, medicine_knowledge, surgery_knowledge, fauna_knowledge,
                    common_sense, language_skill), 
                    CSecondaryStatsStature(intimidation, heat_resistance, cold_resistance)
{
    // Empty constructor other than initializer list
}

CSecondaryStats::CSecondaryStats(CSecondaryStats& old) 
        : CSecondaryStatsAction(old.Athletics(), old.Dexterity(), old.SleightOfHand(), old.Stealth(), old.Lockpicking(),
                                old.Hacking()),
        CSecondaryStatsInteraction(old.Persuasion(), old.Barter(), old.Education(), old.Faith(), old.Xenophobia(), 
                                old.AnimalHandling()),
        CSecondaryStatsKnowledge(old.Wisdom(), old.HistoryKnowledge(), old.MedicineKnowledge(), old.SurgeryKnowledge(),
                                old.FaunaKnowledge(), old.CommonSense(), old.LanguageSkill()),
        CSecondaryStatsStature(old.Intimidation(), old.HeatResistance(), old.ColdResistance())
{
    // Empty constructor other than initializer list
}