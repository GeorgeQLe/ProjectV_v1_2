/*  Copyright 2017 George Le
    Declaration of class Secondary_stats_interaction and its member functions
*/
#ifndef SECONDARY_STATS_INTERACTION_H
#define SECONDARY_STATS_INTERACTION_H

class Secondary_stats_interaction
{
    public:
    Secondary_stats_interaction();
    Secondary_stats_interaction(unsigned int persuasion, unsigned int barter, unsigned int education,
                                unsigned int faith, unsigned int xenophobia, unsigned int animal_handling);
                                
    unsigned int persuasion() const { return m_persuasion; }
    unsigned int barter() const { return m_barter; }
    unsigned int education() const { return m_education; }
    unsigned int faith() const { return m_faith; }
    unsigned int xenophobia() const { return m_xenophobia; }
    unsigned int animal_handling() const { return m_animal_handling; }
    
    bool persuasion_check(unsigned int difficulty_check);
    bool barter_check(unsigned int difficulty_check);
    bool education_check(unsigned int difficulty_check);
    bool faith_check(unsigned int difficulty_check);
    bool xenophobia_check(unsigned int difficulty_check);
    bool animal_handling_check(unsigned int difficulty_check);
    
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