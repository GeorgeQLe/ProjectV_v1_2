/*	Copyright 2017 George Le
	Declaration of the main game controller
*/
#ifndef DIADAL_H
#define DIADAL_H
#include <vector>
#include <memory>

#include "Game/Game.h"
#include "Entity/Primary_character.h"

class CDiadal : public CGame
{
	public:
	CDiadal();
	~CDiadal() {}
	
	// First menu screen that will call the base class CGame's
	// GameMainMenu
	bool TitleMenu();
	// Main game loop that controls the flow of the game's campaign
	void GameLoop();
	// Start the game from the beginning
	void NewGame();
	// Start the game from a certain point
	void LoadGame();
	
	// accessor functions
	bool GameRunning() const { return m_game_running; }
	bool NewGame() const { return m_new_game; }
	
	private:
	bool m_game_running;
	bool m_new_game;
	int m_number_of_party_members;
	
	std::vector<std::shared_ptr<CPrimaryCharacter>> m_list_of_characters;
};

#endif