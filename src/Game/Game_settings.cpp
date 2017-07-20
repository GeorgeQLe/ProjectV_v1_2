/*  Copyright 2017 George Le
    Definition of the member class of the Game_settings class
*/
#include <iostream>
#include "Game/Game_settings.h"
#include "Support/support.h"

Game_settings::Game_settings() : m_number_of_players(1), m_difficulty_level(EASY) 
{
    
}

Game_settings::Game_settings(unsigned int num_players, Difficulty difficulty) 
					: m_number_of_players(num_players), m_difficulty_level(difficulty) 
{
    
}

void Game_settings::game_settings_menu()
{
    bool yes = true;
	int choice = 0;

	while (yes)
	{
		std::cout << "Menu screen\n";
		std::cout << "1. Change number of players\n";
		std::cout << "2. Change difficulty level\n";
		std::cout << "3. Quit menu\n";
		std::cout << "Please input your choice: ";	
		
		choice = get_number_from_user(1, 3);

			switch (choice)
			{
			case 1:
			std::cout << "How many players would you like to have?:(1-2) ";
			set_number_of_players(get_number_from_user(1, 2));
			std::cout << "You chose " << m_number_of_players << std::endl;
			break;
			
			case 2:
			std::cout << "What difficulty would you like to play on? (1 for Easy, 2 for Moderate, 3 for Hard): ";
			set_difficulty(get_number_from_user(1, 3));
			std::cout << "You chose " << m_difficulty_level << std::endl;
			break;
            
            case 3:
            std::cout << "Would you like to stay in the settings menu? (y/n): ";
			yes = get_y_or_n_as_bool();
			break;
			
			default:
			std::cout << "How'd you get here?" << std::endl;
			break;
			}
	}
}

void Game_settings::set_number_of_players(int number_of_players)
{
    m_number_of_players = number_of_players;
}

void Game_settings::set_difficulty(int difficulty_level)
{ 
	m_difficulty_level = static_cast<Difficulty>(difficulty_level);
}