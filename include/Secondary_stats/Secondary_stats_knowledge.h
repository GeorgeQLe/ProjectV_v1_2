/*  Copyright 2017 George Le
    Declaration of Secondary_stats_knowledge class and its member functions
*/
#ifndef SECONDARY_STATS_KNOWLEDGE_H
#define SECONDARY_STATS_KNOWLEDGE_H

class Secondary_stats_knowledge
{
    public:
    Secondary_stats_knowledge();
    Secondary_stats_knowledge(unsigned int wisdom, unsigned int history_knowledge, unsigned int medicine_knowledge, 
                            unsigned surgery_knowledge, unsigned int fauna_knowledge, unsigned int common_sense, 
                            unsigned int language_skill);

    // accessor functions
    unsigned int wisdom() const { return m_wisdom; }
    unsigned int history_knowledge() const { return m_history_knowledge; }
    unsigned int medicine_knowledge() const { return m_medicine_knowledge; }
    unsigned int surgery_knowledge() const { return m_surgery_knowledge; }
    unsigned int fauna_knowledge() const { return m_fauna_knowledge; }
    unsigned int common_sense() const { return m_common_sense; }
    unsigned int language_skill() const { return m_language_skill; }
    
    // saving or difficulty checks depending on the situation
    bool wisdom_check(unsigned int difficulty_check);
    bool history_knowledge_check(unsigned int difficulty_check);
    bool medicine_knowledge_check(unsigned int difficulty_check);
    bool surgery_knowledge_check(unsigned int difficulty_check);
    bool fauna_knowledge_check(unsigned int difficulty_check);
    bool common_sense_check(unsigned int difficulty_check);
    bool language_skill(unsigned int difficulty_check);
    
    private:
    //knowledge based secondary stats
    unsigned int m_wisdom;
    unsigned int m_history_knowledge;
    unsigned int m_medicine_knowledge;
    unsigned int m_surgery_knowledge;
    unsigned int m_fauna_knowledge;
    unsigned int m_common_sense;
    unsigned int m_language_skill;
};

#endif