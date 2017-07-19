#include <iostream>
#include "Game/Game.h"
#include "Support/support.h"

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
			std::cout << "You chose " << number_of_players << std::endl;
			break;
			
			case 2:
			std::cout << "What difficulty would you like to play on? (1 for Easy, 2 for Moderate, 3 for Hard): ";
			set_difficulty(get_number_from_user(1, 3));
			std::cout << "You chose " << difficulty_level << std::endl;
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
    this->number_of_players = number_of_players;
}

void Game_settings::set_difficulty(int difficulty_level)
{ 
	this->difficulty_level = static_cast<Difficulty>(difficulty_level);
}

bool Game::game_main_menu()
{
    bool yes = false;
	int choice;

	if (first_time == true)
	{
		std::cout << "Hello, welcome to " << game_name << "!" << std::endl;
		first_time = false;
	}
		
	while (yes == false)
	{
		std::cout << std::endl;
		std::cout << "1. Play (" << options.get_number_of_players() << " player) game\n";
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
			options.game_settings_menu();
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