/*  Copyright 2017 George Le
    Declaration of CSecondaryStatsStature class and its member functions
*/
#ifndef SECONDARY_STATS_STATURE_H
#define SECONDARY_STATS_STATURE_H

class CSecondaryStatsStature
{
    public:
    CSecondaryStatsStature();
    CSecondaryStatsStature(unsigned int intimidation, 
                            unsigned int heat_resistance, 
                            unsigned int cold_resistance);
    
    unsigned int Intimidation() const { return m_intimidation; }
    unsigned int HeatResistance() const { return m_heat_resistance; }
    unsigned int ColdResistance() const { return m_cold_resistance; }
    
    bool IntimidationCheck(unsigned int difficulty_check);
    bool HeatResistanceCheck(unsigned int difficulty_check);
    bool ColdResistanceCheck(unsigned int difficulty_check);
    
    private:
    //stature based secondary stats
    unsigned int m_intimidation;
    unsigned int m_heat_resistance;
    unsigned int m_cold_resistance;
};

#endif