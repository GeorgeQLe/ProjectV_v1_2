/*  Copyright 2017 George Le
    Declaration of CSecondaryStatsAction class and its member functions
*/
#ifndef SECONDARY_STATS_ACTION_H
#define SECONDARY_STATS_ACTION_H

class CSecondaryStatsAction
{
    public:
    CSecondaryStatsAction();
    CSecondaryStatsAction(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand,
                            unsigned int stealth_skill, unsigned int lockpicking, unsigned int hacking);

    // accessor function
    unsigned int Athletics() const { return m_athletics; }
    unsigned int Dexterity() const { return m_dexterity; }
    unsigned int SleightOfHand() const { return m_sleight_of_hand; }
    unsigned int Stealth() const { return m_stealth_skill; }
    unsigned int Lockpicking() const { return m_lockpicking; }
    unsigned int Hacking() const { return m_hacking; }

    // saving or difficulty checks depending on the situation
    bool AthleticsCheck(unsigned int difficulty_check);
    bool DexterityCheck(unsigned int difficulty_check);
    bool SleightOfHandCheck(unsigned int difficulty_check);
    bool StealthCheck(unsigned int difficulty_check);
    bool LockpickCheck(unsigned int difficulty_check);
    bool HackCheck(unsigned int difficulty_check);
    
    private:
    //action based secondary stats
    unsigned int m_athletics;
    unsigned int m_dexterity;
    unsigned int m_sleight_of_hand;
    unsigned int m_stealth_skill;
    unsigned int m_lockpicking;
    unsigned int m_hacking;  
};

#endif