/*  Copyright 2017 George Le
    Declaration of Secondary_stats_creator class and its member function
*/
#ifndef SECONDARY_STATS_CREATOR_H
#define SECONDARY_STATS_CREATOR_H

#include "Secondary_stats.h"

class Secondary_stats_creator
{
    public:
    Secondary_stats_creator(const std::string& script_name);
    
    void init_secondary_stats_non_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum);
    void init_secondary_stats_custom(Secondary_stats& stats_to_be_init, int player_class_converted_from_enum);
    void on_Read(const std::string& Event_name);
    
    void scenes_Marine_custom(Secondary_stats& stats_to_be_init);
    void scenes_Naval_captain_custom(Secondary_stats& stats_to_be_init);
    void scenes_Lawyer_custom(Secondary_stats& stats_to_be_init);
    void scenes_Armorer_custom(Secondary_stats& stats_to_be_init);
    void scenes_Economist_custom(Secondary_stats& stats_to_be_init);
    
    std::string custom_creation_script;
};

#endif