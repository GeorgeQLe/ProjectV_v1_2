/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryStatsInteraction class
*/
#include "Secondary_stats/Secondary_stats_interaction.h"

CSecondaryStatsInteraction::CSecondaryStatsInteraction() : m_persuasion(1), m_barter(1), m_education(1), m_faith(1), 
                                                            m_xenophobia(1), m_animal_handling(1) 
{
    // Empty constructor except for the initializer list
}

CSecondaryStatsInteraction::CSecondaryStatsInteraction(unsigned int persuasion, unsigned int barter, unsigned int education,
                            unsigned int faith, unsigned int xenophobia, unsigned int animal_handling) :
                            m_persuasion(persuasion), m_barter(barter), m_education(education), m_faith(faith), 
                            m_xenophobia(xenophobia), m_animal_handling(animal_handling)
{
    // Empty constructor except for the initializer list
}

bool CSecondaryStatsInteraction::PersuasionCheck(unsigned int difficulty_check)
{
    if(m_persuasion >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_persuasion;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsInteraction::BarterCheck(unsigned int difficulty_check)
{
    if(m_barter >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_barter;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsInteraction::EducationCheck(unsigned int difficulty_check)
{
    if(m_education >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_education;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsInteraction::FaithCheck(unsigned int difficulty_check)
{
    if(m_faith >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_faith;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsInteraction::XenophobiaCheck(unsigned int difficulty_check)
{
    if(m_xenophobia >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_xenophobia;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsInteraction::AnimalHandlingCheck(unsigned int difficulty_check)
{
    if(m_animal_handling >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_animal_handling;
        return true;
    }
    
    // else return failure
    return false;
}