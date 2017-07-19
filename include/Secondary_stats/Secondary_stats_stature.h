/*  Copyright 2017 George Le
    Declaration of Secondary_stats_stature class and its member functions
*/
#ifndef SECONDARY_STATS_STATURE_H
#define SECONDARY_STATS_STATURE_H

class Secondary_stats_stature
{
    public:
    Secondary_stats_stature();
    Secondary_stats_stature(unsigned int intimidation, 
                            unsigned int heat_resistance, 
                            unsigned int cold_resistance);
    
    unsigned int intimidation() const { return m_intimidation; }
    unsigned int heat_resistance() const { return m_heat_resistance; }
    unsigned int cold_resistance() const { return m_cold_resistance; }
    
    bool intimidation_check(unsigned int difficulty_check);
    bool heat_resistance_check(unsigned int difficulty_check);
    bool cold_resistance_check(unsigned int difficulty_check);
    
    private:
    //stature based secondary stats
    unsigned int m_intimidation;
    unsigned int m_heat_resistance;
    unsigned int m_cold_resistance;
};

#endif