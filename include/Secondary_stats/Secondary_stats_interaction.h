/*  Copyright 2017 George Le
    Declaration of class CSecondaryStatsInteraction and its member functions
*/
#ifndef SECONDARY_STATS_INTERACTION_H
#define SECONDARY_STATS_INTERACTION_H

class CSecondaryStatsInteraction
{
    public:
    CSecondaryStatsInteraction();
    CSecondaryStatsInteraction(unsigned int persuasion, unsigned int barter, unsigned int education,
                                unsigned int faith, unsigned int xenophobia, unsigned int animal_handling);
                                
    unsigned int Persuasion() const { return m_persuasion; }
    unsigned int Barter() const { return m_barter; }
    unsigned int Education() const { return m_education; }
    unsigned int Faith() const { return m_faith; }
    unsigned int Xenophobia() const { return m_xenophobia; }
    unsigned int AnimalHandling() const { return m_animal_handling; }
    
    bool PersuasionCheck(unsigned int difficulty_check);
    bool BarterCheck(unsigned int difficulty_check);
    bool EducationCheck(unsigned int difficulty_check);
    bool FaithCheck(unsigned int difficulty_check);
    bool XenophobiaCheck(unsigned int difficulty_check);
    bool AnimalHandlingCheck(unsigned int difficulty_check);
    
    private:
    //interaction based secondary stats
    unsigned int m_persuasion;
    unsigned int m_barter;
    unsigned int m_education;
    unsigned int m_faith;
    unsigned int m_xenophobia;
    unsigned int m_animal_handling;
};

#endif