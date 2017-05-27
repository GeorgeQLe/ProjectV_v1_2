/*  Copyright 2017 George Le

*/
#include "character_class_information.h"

Player_class_catalog::Player_class_catalog(const Job& player_class) : m_class_stats(nullptr)
{
    get_class_information(player_class);
}

void Player_class_catalog::get_class_information(const Job& player_class)
{
    if(m_class_stats == nullptr)
    {
        switch(player_class)
        {
            case 1:
            m_class_stats = new Marine_player_information;
            break;
            case 2:
            m_class_stats = new Naval_captain_information;
            break;
            case 3:
            m_class_stats = new Lawyer_information;
            break;
            case 4:
            m_class_stats = new Armorer_information;
            break;
            case 5:
            m_class_stats = new Economist_information;
            default:
            break;
        }
    }
}