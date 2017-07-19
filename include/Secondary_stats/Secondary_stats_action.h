/*  Copyright 2017 George Le
    Declaration of Secondary_stats_action class and its member functions
*/
#ifndef SECONDARY_STATS_ACTION_H
#define SECONDARY_STATS_ACTION_H

class Secondary_stats_action
{
    public:
    Secondary_stats_action();
    Secondary_stats_action(unsigned int athletics, unsigned int dexterity, unsigned int sleight_of_hand,
                            unsigned int stealth_skill, unsigned int lockpicking, unsigned int hacking);

    // accessor function
    unsigned int athletics() const { return m_athletics; }
    unsigned int dexterity() const { return m_dexterity; }
    unsigned int sleight_of_hand() const { return m_sleight_of_hand; }
    unsigned int stealth() const { return m_stealth_skill; }
    unsigned int lockpicking() const { return m_lockpicking; }
    unsigned int hacking() const { return m_hacking; }

    // saving or difficulty checks depending on the situation
    bool athletics_check(unsigned int difficulty_check);
    bool dexterity_check(unsigned int difficulty_check);
    bool sleight_of_hand_check(unsigned int difficulty_check);
    bool stealth_check(unsigned int difficulty_check);
    bool lockpick_check(unsigned int difficulty_check);
    bool hack_check(unsigned int difficulty_check);
    
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