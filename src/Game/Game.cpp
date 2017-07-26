/*	Copyright 2017 George Le
	Definition of the member functions of the Game class
*/
#include <iostream>
#include "Game/Game.h"
#include "Support/support.h"

// default constructor
CGame::CGame() : m_options(1, EASY), m_game_name("Default game name"), m_first_time(true)
{
	// Empty constructor except for the initializer list
}

CGame::CGame(unsigned int num_players, DifficultyOfGame difficulty, std::string name_of_game) 
			: m_options(num_players, difficulty), m_game_name(name_of_game), m_first_time(true)
{
	// Empty constructor except for the initializer list
}

CGame::~CGame()
{
	// Empty destructor
}

bool CGame::GameMainMenu()
{
    bool f_yes = false;
	int f_choice;

	if (m_first_time == true)
	{
		std::cout << "Hello, welcome to " << m_game_name << "!" << std::endl;
		m_first_time = false;
	}
		
	while (f_yes == false)
	{
		std::cout << std::endl;
		std::cout << "1. Play (" << m_options.NumberOfPlayers() << " player) game\n";
		std::cout << "2. Settings\n";
		std::cout << "3. Quit\n";
		std::cout << "Input: ";
		f_choice = get_number_from_user(1, 3);

		switch (f_choice)
		{
		case 1:
		std::cout << "\n";
			return true;
			break;
			
		case 2:
			std::cout << "Going to settings!" << std::endl;
			m_options.GameSettingsMenu();
			break;
			
		default:
			std::cout << "How'd you get here?" << std::endl;
			break;
		}
		
		if (f_choice == 1)
		{
			std::cout << "Quitted from game!\n";
			std::cout << "Do you want to quit game? (y/n - Returns to main menu)\nInput:";
		}
		else if (f_choice == 2)
		{
			std::cout << "Quitted from settings!\n";
			std::cout << "Do you want to quit game? (y/n - Returns to main menu)\nInput:";
		}
		else if (f_choice == 3)
		{
			std::cout << "Are you sure you want to quit? (y/n): ";
		}
		f_yes = get_y_or_n_as_bool();
	}
	return false;
}