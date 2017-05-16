/*  Copyright 2016 George Le

*/
#include <iostream>
#include "ingame_entity.h"
#include "support.h"

void Ingame_entity_human::set_information()
{
    std::cout << "This is a temporary build\n";
    std::cout << "What would you like your ingame name to be?\nInput:";
    m_entity_name = getline_from_user_restricted(1, 10);
    std::cout << "What is your preferred gender?\n1.Male\n2.Female\n3.Other\nInput:";
    m_entity_gender = static_cast<Gender>(get_number_from_user(1,3));
    std::cout << "What is your race?\n1.White\n2.Black\n3.Asian or Pacific Islander\n4.Hispanic\n5.Indigenous People\n6.Other\nInput:";
    m_entity_race = static_cast<Race>(get_number_from_user(1, 6));
}