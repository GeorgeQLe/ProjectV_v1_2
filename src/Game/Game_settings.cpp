/*  Copyright 2017 George Le
    Definition of the member class of the CGameSettings class
*/
#include <iostream>
#include "Game/Game_settings.h"
#include "Support/support.h"

CGameSettings::CGameSettings() : m_number_of_players(1), m_difficulty_level(EASY) 
{
    // Empty constructor execpt for initializer list
}

CGameSettings::CGameSettings(unsigned int num_players, DifficultyOfGame difficulty) 
					: m_number_of_players(num_players), m_difficulty_level(difficulty) 
{
    // Empty constructor execpt for initializer list
}

CGameSettings::~CGameSettings()
{
	// Empty destructor
}

void CGameSettings::GameSettingsMenu()
{
    bool f_yes = true;
	int f_choice = 0;

	while (f_yes)
	{
		std::cout << "Menu screen\n";
		std::cout << "1. Change number of players\n";
		std::cout << "2. Change difficulty level\n";
		std::cout << "3. Quit menu\n";
		std::cout << "Please input your choice: ";	
		
		f_choice = get_number_from_user(1, 3);

			switch (f_choice)
			{
			case 1:
			std::cout << "How many players would you like to have?:(1-2) ";
			SetNumberOfPlayers(get_number_from_user(1, 2));
			std::cout << "You chose " << m_number_of_players << std::endl;
			break;
			
			case 2:
			std::cout << "What difficulty would you like to play on? (1 for Easy, 2 for Moderate, 3 for Hard): ";
			SetDifficulty(get_number_from_user(1, 3));
			std::cout << "You chose " << m_difficulty_level << std::endl;
			break;
            
            case 3:
            std::cout << "Would you like to stay in the settings menu? (y/n): ";
			f_yes = get_y_or_n_as_bool();
			break;
			
			default:
			std::cout << "How'd you get here?" << std::endl;
			break;
			}
	}
}

void CGameSettings::SetNumberOfPlayers(int number_of_players)
{
    m_number_of_players = number_of_players;
}

void CGameSettings::SetDifficulty(int difficulty_level)
{ 
	m_difficulty_level = static_cast<DifficultyOfGame>(difficulty_level);
}