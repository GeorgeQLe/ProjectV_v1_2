/*  Copyright 2017 George Le
    Declaration of CSecondaryStatsCreator class and its member function
*/
#ifndef SECONDARY_STATS_CREATOR_H
#define SECONDARY_STATS_CREATOR_H

#include "Secondary_stats.h"

class CSecondaryStatsCreator
{
    public:
    CSecondaryStatsCreator(const std::string& script_name);
    
    CSecondaryStats InitSecondaryStatsNonCustom(int player_class_converted_from_enum);
    void InitSecondaryStatsCustom(CSecondaryStats& stats_to_be_init, int player_class_converted_from_enum);
    void OnRead(const std::string& Event_name);
    
    void ScenesMarineCustom(CSecondaryStats& stats_to_be_init);
    void ScenesNavalCaptainCustom(CSecondaryStats& stats_to_be_init);
    void ScenesLawyerCustom(CSecondaryStats& stats_to_be_init);
    void ScenesArmorerCustom(CSecondaryStats& stats_to_be_init);
    void ScenesEconomistCustom(CSecondaryStats& stats_to_be_init);
    
    private:
    std::string custom_creation_script;
};

#endif