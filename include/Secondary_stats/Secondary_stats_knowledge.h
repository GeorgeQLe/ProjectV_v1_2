/*  Copyright 2017 George Le
    Declaration of CSecondaryStatsKnowledge class and its member functions
*/
#ifndef SECONDARY_STATS_KNOWLEDGE_H
#define SECONDARY_STATS_KNOWLEDGE_H

class CSecondaryStatsKnowledge
{
    public:
    CSecondaryStatsKnowledge();
    CSecondaryStatsKnowledge(unsigned int wisdom, unsigned int history_knowledge, unsigned int medicine_knowledge, 
                            unsigned surgery_knowledge, unsigned int fauna_knowledge, unsigned int common_sense, 
                            unsigned int language_skill);

    // accessor functions
    unsigned int Wisdom() const { return m_wisdom; }
    unsigned int HistoryKnowledge() const { return m_history_knowledge; }
    unsigned int MedicineKnowledge() const { return m_medicine_knowledge; }
    unsigned int SurgeryKnowledge() const { return m_surgery_knowledge; }
    unsigned int FaunaKnowledge() const { return m_fauna_knowledge; }
    unsigned int CommonSense() const { return m_common_sense; }
    unsigned int LanguageSkill() const { return m_language_skill; }
    
    // saving or difficulty checks depending on the situation
    bool WisdomCheck(unsigned int difficulty_check);
    bool HistoryKnowledgeCheck(unsigned int difficulty_check);
    bool MedicineKnowledgeCheck(unsigned int difficulty_check);
    bool SurgeryKnowledgeCheck(unsigned int difficulty_check);
    bool FaunaKnowledgeCheck(unsigned int difficulty_check);
    bool CommonSenseCheck(unsigned int difficulty_check);
    bool LanguageSkill(unsigned int difficulty_check);
    
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