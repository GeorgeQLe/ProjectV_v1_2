/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats_knowledge class
*/
#include "Secondary_stats/Secondary_stats_knowledge.h"

Secondary_stats_knowledge::Secondary_stats_knowledge() : m_wisdom(0), m_history_knowledge(0), m_medicine_knowledge(0), 
                                m_surgery_knowledge(0), m_fauna_knowledge(0), m_common_sense(0), m_language_skill(0) 
{
    // Empty constructor other than initializer list
}

Secondary_stats_knowledge::Secondary_stats_knowledge(unsigned int wisdom, unsigned int history_knowledge, 
                            unsigned int medicine_knowledge, unsigned surgery_knowledge, unsigned int fauna_knowledge, 
                            unsigned int common_sense, unsigned int language_skill) 
                    : m_wisdom(wisdom), m_history_knowledge(history_knowledge), m_medicine_knowledge(medicine_knowledge), 
                    m_surgery_knowledge(surgery_knowledge), m_fauna_knowledge(fauna_knowledge), m_common_sense(common_sense),
                    m_language_skill(language_skill) 
{
    // Empty constructor other than initializer list
}

bool Secondary_stats_knowledge::wisdom_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::history_knowledge_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::medicine_knowledge_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::surgery_knowledge_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::fauna_knowledge_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::common_sense_check(unsigned int difficulty_check)
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

bool Secondary_stats_knowledge::language_skill(unsigned int difficulty_check)
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