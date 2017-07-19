/*	Copyright 2017 George Le
	Declaration of the main game controller
*/
#ifndef DIADAL_H
#define DIADAL_H
#include <vector>
#include <memory>

#include "Game/Game.h"
#include "Entity/Primary_character.h"

class Diadal
{
	public:
	Diadal();
	~Diadal() {}
	
	void game_loop();
	bool game_menu();
	bool game_running() const { return m_game_running; }
	
	void new_game();
	
	private:
	Game standard_game;
	bool m_game_running;
	bool m_new_game;
	int m_number_of_party_members;
	
	std::vector<std::shared_ptr<Primary_character>> m_list_of_characters;
};

#endif