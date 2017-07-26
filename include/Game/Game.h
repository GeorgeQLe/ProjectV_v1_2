/*	Copyright 2017 George Le
	Declaration of the Game class and its member functions
*/
#ifndef GAME_H
#define GAME_H

#include <string>

#include "Game_settings.h"

class CGame
{
	public:
	CGame();
	CGame(unsigned int num_players, DifficultyOfGame difficulty, std::string name_of_game);
	~CGame();
	
	bool GameMainMenu();
	
	// accessor function
	int Difficulty() const { return m_options.Difficulty(); }
	
	private:
	CGameSettings m_options;
	std::string m_game_name;
	bool m_first_time;
};

#endif