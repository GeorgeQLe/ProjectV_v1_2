#ifndef HOSTILE_H
#define HOSTILE_H

#include <string>

class Hostile
{
    public:
    Hostile() : hostile_name("Default name"), hostile_stats()
    
    private:
    std::string hostile_name;
    Primary_stats hostile_stats;
};

#endif