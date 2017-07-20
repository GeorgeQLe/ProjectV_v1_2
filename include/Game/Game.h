/*	Copyright 2017 George Le
	Declaration of the Game class and its member functions
*/
#ifndef GAME_H
#define GAME_H

#include <string>

#include "Game_settings.h"

class Game
{
	public:
	Game();
	Game(unsigned int num_players, Difficulty difficulty, std::string name_of_game);
	~Game();
	
	bool game_main_menu();
	
	// accessor function
	int difficulty() const { return m_options.difficulty(); }
	
	private:
	Game_settings m_options;
	std::string m_game_name;
	bool m_first_time;
};

#endif