#ifndef GAME_H
#define GAME_H

#include <string>

enum Difficulty { EASY = 0, MEDIUM = 3, HARD = 5};

class Game_settings
{
	public:
	//default number of players is 1,
	Game_settings() : number_of_players(1), difficulty_level(EASY) {}
	Game_settings(unsigned int num_players, Difficulty difficulty) 
					: number_of_players(num_players), difficulty_level(difficulty) {}
	void game_settings_menu();
	int get_number_of_players() const { return number_of_players; }
	int get_difficulty() const { return static_cast<int>(difficulty_level); }
	
	private:
	void set_number_of_players(int number_of_players);
	void set_difficulty(int difficulty_level);

	unsigned int number_of_players;
	Difficulty difficulty_level;
};

class Game
{
	public:
	Game() : options(1, EASY), game_name("Default game name"), first_time(true) {}
	Game(unsigned int num_players, Difficulty difficulty, std::string name_of_game) 
			: options(num_players, difficulty), game_name(name_of_game), first_time(true) {} 
	bool game_main_menu();
	int get_difficulty() const { return options.get_difficulty(); }
	
	private:
	Game_settings options;
	std::string game_name;
	bool first_time;
};

#endif