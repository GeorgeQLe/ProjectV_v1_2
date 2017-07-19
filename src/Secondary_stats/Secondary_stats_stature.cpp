/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats_stature class
*/
#include "Secondary_stats/Secondary_stats_stature.h"

Secondary_stats_stature::Secondary_stats_stature() : m_intimidation(1), m_heat_resistance(1), m_cold_resistance(1)
{
    // Empty constructor other than initializer list
}

Secondary_stats_stature::Secondary_stats_stature(unsigned int intimidation, unsigned int heat_resistance, 
                                                unsigned int cold_resistance)
                                                : m_intimidation(intimidation), m_heat_resistance(heat_resistance), 
                                                m_cold_resistance(cold_resistance)
{
    // Empty constructor other than initializer list
}

bool Secondary_stats_stature::intimidation_check(unsigned int difficulty_check)
{
    if(m_intimidation >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_intimidation;
        return true;
    }
    
    // else return failure
    return false;
}

bool Secondary_stats_stature::heat_resistance_check(unsigned int difficulty_check)
{
    if(m_heat_resistance >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_heat_resistance;
        return true;
    }
    
    // else return failure
    return false;
}

bool Secondary_stats_stature::cold_resistance_check(unsigned int difficulty_check)
{
    if(m_cold_resistance >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++m_cold_resistance;
        return true;
    }
    
    // else return failure
    return false;
}