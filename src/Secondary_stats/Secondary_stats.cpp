/*  Copyright 2017 George Le
    Definition of member functions of the Secondary_stats class
*/
#include <iostream>
#include "Secondary_stats/Secondary_stats.h"
#include "support.h"

bool Secondary_stats::check_stat(unsigned int& your_stat, unsigned int difficulty_check)
{
    if(your_stat >= difficulty_check)
    {
        // passed the check, reward is pass and increment stat
        ++your_stat;
        return true;
    }
    // else return failure
    return false;
}