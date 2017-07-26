/*  Copyright 2017 George Le
    Declaration of the CGameSettings class and its member functions
*/
#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

enum DifficultyOfGame { EASY = 0, MEDIUM = 3, HARD = 5};

class CGameSettings
{
	public:
	//default number of players is 1,
	CGameSettings();
	CGameSettings(unsigned int num_players, DifficultyOfGame difficulty);
	~CGameSettings();
	
	void GameSettingsMenu();
	
	// accessor functions
	int NumberOfPlayers() const { return m_number_of_players; }
	int Difficulty() const { return static_cast<int>(m_difficulty_level); }
	
	private:
	void SetNumberOfPlayers(int number_of_players);
	void SetDifficulty(int difficulty_level);

	unsigned int m_number_of_players;
	DifficultyOfGame m_difficulty_level;
};

#endif