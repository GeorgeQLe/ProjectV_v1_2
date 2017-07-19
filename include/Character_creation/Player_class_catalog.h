/*  Copyright 2017 George Le
    Stores all of my primary_character stats for use in character creation
*/
#ifndef PLAYER_CLASS_CATALOG_H
#define PLAYER_CLASS_CATALOG_H

#include "Entity/Ingame_entity.h"
#include "Primary_stats/Primary_stats.h"

class Player_information
{
    public:
    Player_information() : primary_stats(1, 1, 1, 1, 1) {}
    Player_information(int strength, int leadership, int intelligence, int character, int endurance)
                        : primary_stats(strength, leadership, intelligence, character, endurance) {}
    
    int get_strength() { return primary_stats.strength(); }
    int get_leadership() { return primary_stats.leadership(); }
    int get_intelligence() { return primary_stats.intelligence(); }
    int get_character() { return primary_stats.character(); }
    int get_endurance() { return primary_stats.endurance(); }
    
    protected:
    Primary_attributes primary_stats;
    Secondary_attributes secondary_stats;
};

// Marine - High Strength(5), Moderate Leadership(4), Moderate Intelligence(3)
//Moderate Character (3), High Endurance (5)
// *He really likes COD... the fish.*
// Combat Perk: Gun Club Member *+ 5 weapon damage*
// Innate Perk: Sprinter *+ 5 stamina, + 5 speed*
// Skill Perk: Shot Marksman *+ 5 weapon accuracy*
class Marine_player_information : public Player_information
{
    public:
    Marine_player_information(): Player_information(5, 4, 3, 3, 5) {}
};

class Naval_captain_information : public Player_information
{
    public:
    Naval_captain_information(): Player_information(4, 5, 5, 3, 3) {}
};

class Lawyer_information : public Player_information
{
    public:
    Lawyer_information(): Player_information(2, 3, 7, 5, 3) {}
};

class Armorer_information : public Player_information
{
    public:
    Armorer_information() : Player_information(4, 3, 5, 3, 5) {}
};

class Economist_information : public Player_information
{
    public:
    Economist_information() : Player_information() {}
};

class Player_class_catalog
{
    public:
    Player_class_catalog() {}
    Player_class_catalog(const Job& player_class);
    ~Player_class_catalog() { delete m_class_stats; }
    
    void get_class_information(const Job& player_class);
    
    int get_strength() { return m_class_stats->get_strength(); }
    int get_leadership() { return m_class_stats->get_leadership(); }
    int get_intelligence() { return m_class_stats->get_intelligence(); }
    int get_character() { return m_class_stats->get_character(); }
    int get_endurance() { return m_class_stats->get_endurance(); }
    private:
    Player_information* m_class_stats;
};

#endif