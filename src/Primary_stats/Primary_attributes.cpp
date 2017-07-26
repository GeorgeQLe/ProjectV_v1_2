/*  Copyright 2017 George Le
    Definition of member functions of the CPrimaryAttributes class
*/
#include <iostream>
#include "Primary_stats/Primary_attributes.h"

CPrimaryAttributes::CPrimaryAttributes() : m_strength(1), m_leadership(1), m_intelligence(1), m_character(1), m_endurance(1)
{
    // Empty constructor other than initializer list
}

CPrimaryAttributes::CPrimaryAttributes(int strength, int leadership, int intelligence, int character, int endurance) :
						m_strength{strength}, m_leadership{leadership}, m_intelligence{intelligence}, 
						m_character{character}, m_endurance{endurance} 
{
    // Empty constructor other than initializer list
}

void CPrimaryAttributes::ModifyStat(Primary_attribute to_be_Modified, int new_value)
{
	switch(to_be_Modified)
	{
		case 1:
		if(new_value > 0)
		{
			m_strength = new_value;
		}
		else
		{
			std::cout << "Strength can't be less than zero\n";
		}
		break;
		case 2:
		if(new_value > 0)
		{
			m_leadership = new_value;
		}
		else
		{
			std::cout << "Leadership can't be less than zero\n";
		}
		break;
		case 3:
		if(new_value > 0)
		{
			m_intelligence = new_value;
		}
		else
		{
			std::cout << "Intelligence can't be less than zero\n";
		}
		break;
		case 4:
		if(new_value > 0)
		{
			m_character = new_value;
		}
		else
		{
			std::cout << "Character can't be less than zero\n";
		}
		break;
		case 5:
		if(new_value > 0)
		{
			m_endurance = new_value;
		}
		else
		{
			std::cout << "Endurance can't be less than zero\n";
		}
		break;
		default:
		std::cout << "Not a valid stat\n";
		break;
	}
}