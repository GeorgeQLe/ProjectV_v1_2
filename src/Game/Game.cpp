/*	Copyright 2017 George Le
	Definition of the member functions of the Game class
*/
#include <iostream>
#include "Game/Game.h"
#include "Support/support.h"

Game::Game() : m_options(1, EASY), m_game_name("Default game name"), m_first_time(true)
{
	// Empty constructor except for the initializer list
}

Game::Game(unsigned int num_players, Difficulty difficulty, std::string name_of_game) 
			: m_options(num_players, difficulty), m_game_name(name_of_game), m_first_time(true)
{
	// Empty constructor except for the initializer list
}

Game::~Game()
{
	// Empty destructor
}

bool Game::game_main_menu()
{
    bool yes = false;
	int choice;

	if (m_first_time == true)
	{
		std::cout << "Hello, welcome to " << m_game_name << "!" << std::endl;
		m_first_time = false;
	}
		
	while (yes == false)
	{
		std::cout << std::endl;
		std::cout << "1. Play (" << m_options.number_of_players() << " player) game\n";
		std::cout << "2. Settings\n";
		std::cout << "3. Quit\n";
		std::cout << "Input: ";
		choice = get_number_from_user(1, 3);

		switch (choice)
		{
		case 1:
		std::cout << "\n";
			return true;
			break;
		case 2:
			std::cout << "Going to settings!" << std::endl;
			m_options.game_settings_menu();
			break;
		default:
			break;
		}
		
		if (choice == 1)
		{
			std::cout << "Quitted from game!\n";
			std::cout << "Do you want to quit game? (y/n - Returns to main menu)\nInput:";
		}
		else if (choice == 2)
		{
			std::cout << "Quitted from settings!\n";
			std::cout << "Do you want to quit game? (y/n - Returns to main menu)\nInput:";
		}
		else if (choice == 3)
		{
			std::cout << "Are you sure you want to quit? (y/n): ";
		}
		yes = get_y_or_n_as_bool();
	}
	return false;
}