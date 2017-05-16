#ifndef HOSTILE_H
#define HOSTILE_H

#include <string>

class Hostile
{
    public:
    Hostile() : hostile_name("Default name"), hostile_stats(0, 0, 0, 0, 0, 1, 10, 10, 0, 1) {}
    
    private:
    std::string hostile_name;
    Primary_stats hostile_stats;
};

#endif