#ifndef DIADAL_H
#define DIADAL_H
#include <map>
#include "game.h"
#include "primary_character.h"

class Diadal
{
	public:
	Diadal() : standard_game(1, EASY, "Diadal"), m_game_running(true), m_new_game(true), number_of_party_members(0) {}
	
	void game_loop();
	bool game_menu();
	bool game_running() const { return m_game_running; }
	
	void new_game();
	
	private:
	Game standard_game;
	bool m_game_running;
	bool m_new_game;
	int number_of_party_members;
	
	std::map<int, Primary_character*> list_of_characters;
	const std::string script_name;
};

#endif