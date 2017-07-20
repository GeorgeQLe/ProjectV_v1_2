/*  Copyright 2017 George Le
    Declaration of the Game_settings class and its member functions
*/
#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

enum Difficulty { EASY = 0, MEDIUM = 3, HARD = 5};

class Game_settings
{
	public:
	//default number of players is 1,
	Game_settings();
	Game_settings(unsigned int num_players, Difficulty difficulty);
	
	void game_settings_menu();
	
	// accessor functions
	int number_of_players() const { return m_number_of_players; }
	int difficulty() const { return static_cast<int>(m_difficulty_level); }
	
	private:
	void set_number_of_players(int number_of_players);
	void set_difficulty(int difficulty_level);

	unsigned int m_number_of_players;
	Difficulty m_difficulty_level;
};

#endif