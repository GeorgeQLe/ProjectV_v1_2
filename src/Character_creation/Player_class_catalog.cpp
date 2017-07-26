/*  Copyright 2017 George Le
    Definitions of member function of the CPlayerClassCatalog class
*/
#include "Character_creation/Player_class_catalog.h"

CPlayerClassCatalog::CPlayerClassCatalog(const Job& player_class) : m_class_stats(nullptr)
{
    GetClassInformation(player_class);
}

void CPlayerClassCatalog::GetClassInformation(const Job& player_class)
{
    if(m_class_stats == nullptr)
    {
        switch(player_class)
        {
            case 1:
            m_class_stats = new CMarinePlayerInformation;
            break;
            case 2:
            m_class_stats = new CNavalCaptainInformation;
            break;
            case 3:
            m_class_stats = new CLawyerInformation;
            break;
            case 4:
            m_class_stats = new CArmorerInformation;
            break;
            case 5:
            m_class_stats = new CEconomistInformation;
            default:
            break;
        }
    }
}