/*  Copyright 2017 George Le
    Definition of member functions of the CSecondaryStatsAction class
*/
#include "Secondary_stats/Secondary_stats_action.h"

CSecondaryStatsAction::CSecondaryStatsAction() : m_athletics(1), m_dexterity(1), m_sleight_of_hand(1), m_stealth_skill(1), 
                        m_lockpicking(1), m_hacking(1)
{
    // Empty constructor other than initializer list
}

CSecondaryStatsAction::CSecondaryStatsAction(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand,
                            unsigned int stealth_skill, unsigned int lockpicking, unsigned int hacking)
                            : m_athletics(athletics), m_dexterity(dexterity), m_sleight_of_hand(sleight_of_hand),
                            m_stealth_skill(stealth_skill), m_lockpicking(lockpicking), m_hacking(hacking)
{
    // Empty constructor other than initializer list
}

bool CSecondaryStatsAction::AthleticsCheck(unsigned int difficulty_check)
{
    if(m_athletics >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_athletics;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsAction::DexterityCheck(unsigned int difficulty_check)
{
    if(m_dexterity >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_dexterity;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsAction::SleightOfHandCheck(unsigned int difficulty_check)
{
    if(m_sleight_of_hand >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_sleight_of_hand;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsAction::StealthCheck(unsigned int difficulty_check)
{
    if(m_stealth_skill >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_stealth_skill;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsAction::LockpickCheck(unsigned int difficulty_check)
{
    if(m_lockpicking >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_lockpicking;
        return true;
    }
    
    // else return failure
    return false;
}

bool CSecondaryStatsAction::HackCheck(unsigned int difficulty_check)
{
    if(m_hacking >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_hacking;
        return true;
    }
    
    // else return failure
    return false;
}