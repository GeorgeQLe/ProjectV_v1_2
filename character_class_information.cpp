#include "character_class_information.h"

Player_class_catalog::Player_class_catalog(const Job& player_class)
{
    get_class_information(player_class);
}

void Player_class_catalog::get_class_information(const Job& player_class)
{
    switch(player_class)
    {
        case 1:
        class_stats = new Marine_player_information;
        break;
        case 2:
        class_stats = new Naval_captain_information;
        break;
        case 3:
        class_stats = new Lawyer_information;
        break;
        case 4:
        class_stats = new Armorer_information;
        break;
        case 5:
        class_stats = new Economist_information;
        default:
        break;
    }
}