/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats_knowledge class
*/

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