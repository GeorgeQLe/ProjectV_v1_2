/*  Copyright 2017 George Le
    Stores all of my primary_character stats for use in character creation
*/
#ifndef PLAYER_CLASS_CATALOG_H
#define PLAYER_CLASS_CATALOG_H

#include "Entity/Ingame_entity.h"
#include "Primary_stats/Primary_stats.h"

class CPlayerInformation
{
    public:
    CPlayerInformation() : m_primary_stats(1, 1, 1, 1, 1) {}
    CPlayerInformation(int strength, int leadership, int intelligence, int character, int endurance)
                        : m_primary_stats(strength, leadership, intelligence, character, endurance) {}
    
    int GetStrength() { return m_primary_stats.Strength(); }
    int GetLeadership() { return m_primary_stats.Leadership(); }
    int GetIntelligence() { return m_primary_stats.Intelligence(); }
    int GetCharacter() { return m_primary_stats.Character(); }
    int GetEndurance() { return m_primary_stats.Endurance(); }
    
    protected:
    CPrimaryAttributes m_primary_stats;
    CSecondaryAttributes m_secondary_stats;
};

// Marine - High Strength(5), Moderate Leadership(4), Moderate Intelligence(3)
//Moderate Character (3), High Endurance (5)
// *He really likes COD... the fish.*
// Combat Perk: Gun Club Member *+ 5 weapon damage*
// Innate Perk: Sprinter *+ 5 stamina, + 5 speed*
// Skill Perk: Shot Marksman *+ 5 weapon accuracy*
class CMarinePlayerInformation : public CPlayerInformation
{
    public:
    CMarinePlayerInformation(): CPlayerInformation(5, 4, 3, 3, 5) {}
};

class CNavalCaptainInformation : public CPlayerInformation
{
    public:
    CNavalCaptainInformation(): CPlayerInformation(4, 5, 5, 3, 3) {}
};

class CLawyerInformation : public CPlayerInformation
{
    public:
    CLawyerInformation(): CPlayerInformation(2, 3, 7, 5, 3) {}
};

class CArmorerInformation : public CPlayerInformation
{
    public:
    CArmorerInformation() : CPlayerInformation(4, 3, 5, 3, 5) {}
};

class CEconomistInformation : public CPlayerInformation
{
    public:
    CEconomistInformation() : CPlayerInformation() {}
};

class CPlayerClassCatalog
{
    public:
    CPlayerClassCatalog() {}
    CPlayerClassCatalog(const Job& player_class);
    ~CPlayerClassCatalog() { delete m_class_stats; }
    
    void GetClassInformation(const Job& player_class);
    
    int GetStrength() { return m_class_stats->GetStrength(); }
    int GetLeadership() { return m_class_stats->GetLeadership(); }
    int GetIntelligence() { return m_class_stats->GetIntelligence(); }
    int GetCharacter() { return m_class_stats->GetCharacter(); }
    int GetEndurance() { return m_class_stats->GetEndurance(); }
    private:
    CPlayerInformation* m_class_stats;
};

#endif