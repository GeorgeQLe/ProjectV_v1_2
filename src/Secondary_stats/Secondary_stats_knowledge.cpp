/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryStatsKnowledge class
*/
#include "Secondary_stats/Secondary_stats_knowledge.h"

CSecondaryStatsKnowledge::CSecondaryStatsKnowledge() : m_wisdom(0), m_history_knowledge(0), m_medicine_knowledge(0), 
                                m_surgery_knowledge(0), m_fauna_knowledge(0), m_common_sense(0), m_language_skill(0) 
{
    // Empty constructor other than initializer list
}

CSecondaryStatsKnowledge::CSecondaryStatsKnowledge(unsigned int wisdom, unsigned int history_knowledge, 
                            unsigned int medicine_knowledge, unsigned surgery_knowledge, unsigned int fauna_knowledge, 
                            unsigned int common_sense, unsigned int language_skill) 
                    : m_wisdom(wisdom), m_history_knowledge(history_knowledge), m_medicine_knowledge(medicine_knowledge), 
                    m_surgery_knowledge(surgery_knowledge), m_fauna_knowledge(fauna_knowledge), m_common_sense(common_sense),
                    m_language_skill(language_skill) 
{
    // Empty constructor other than initializer list
}

bool CSecondaryStatsKnowledge::WisdomCheck(unsigned int difficulty_check)
{
    if(m_wisdom >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_wisdom;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::HistoryKnowledgeCheck(unsigned int difficulty_check)
{
    if(m_history_knowledge >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_history_knowledge;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::MedicineKnowledgeCheck(unsigned int difficulty_check)
{
    if(m_medicine_knowledge >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_medicine_knowledge;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::SurgeryKnowledgeCheck(unsigned int difficulty_check)
{
    if(m_surgery_knowledge >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_surgery_knowledge;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::FaunaKnowledgeCheck(unsigned int difficulty_check)
{
    if(m_fauna_knowledge >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_fauna_knowledge;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::CommonSenseCheck(unsigned int difficulty_check)
{
    if(m_common_sense >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_common_sense;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsKnowledge::LanguageSkill(unsigned int difficulty_check)
{
    if(m_language_skill >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_language_skill;
        return true;
    }
    
    // else return failure
    return false;
}