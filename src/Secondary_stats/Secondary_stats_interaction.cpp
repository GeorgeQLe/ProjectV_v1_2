/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats_interaction class
*/
#include "Secondary_stats/Secondary_stats_interaction.h"

Secondary_stats_interaction::Secondary_stats_interaction() : m_persuasion(1), m_barter(1), m_education(1), m_faith(1), 
                                                            m_xenophobia(1), m_animal_handling(1) 
{
    
}

Secondary_stats_interaction::Secondary_stats_interaction(unsigned int persuasion, unsigned int barter, unsigned int education,
                            unsigned int faith, unsigned int xenophobia, unsigned int animal_handling) :
                            m_persuasion(persuasion), m_barter(barter), m_education(education), m_faith(faith), 
                            m_xenophobia(xenophobia), m_animal_handling(animal_handling)
{
    
}

bool Secondary_stats_interaction::persuasion_check(unsigned int difficulty_check)
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

bool Secondary_stats_interaction::barter_check(unsigned int difficulty_check)
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

bool Secondary_stats_interaction::education_check(unsigned int difficulty_check)
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

bool Secondary_stats_interaction::faith_check(unsigned int difficulty_check)
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

bool Secondary_stats_interaction::xenophobia_check(unsigned int difficulty_check)
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

bool Secondary_stats_interaction::animal_handling_check(unsigned int difficulty_check)
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