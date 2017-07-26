/*	Copyright 2016 George Le
    Definitions of functions declared in Diadal.h
*/
#include <iostream>
#include "Diadal/Diadal.h"
#include "Combat_manager/Combat_manager.h"
#include "Support/support.h"

CDiadal::CDiadal() :
        CGame(1, EASY, "Diadal"),
        m_game_running(true), 
        m_new_game(true), 
        m_number_of_party_members(0)
{
    // when the game starts up, print out the game's introduction
    read_files("Diadal_script_intro.txt");
}

void CDiadal::GameLoop()
{
    //game loop
    while(m_game_running)
    {
        std::cout << "Select an option:\n";
        std::cout << "1. New game\n";
        std::cout << "2. Start from game checkpoint\n";
        std::cout << "3. Back\nInput:";
        int choice = get_number_from_user(1, 3);
        std::cout << std::endl;
        if(choice == 1)
        {
            NewGame();
        }
        else if(choice == 2)
        {
            if(m_new_game != false)
            {
                //load saved game    
            }
        }
        else if(choice == 3)
        {
            m_game_running = false;
        }
    }
}

bool CDiadal::TitleMenu()
{
    if(GameMainMenu())
    {
        m_game_running = true;
    }
    else
    {
        m_game_running = false;
    }
    
    return m_game_running;
}

void CDiadal::NewGame()
{
    std::shared_ptr<CCombatManager> f_combat_system = CCombatManager::GetInstance();
    
    if(m_new_game)
    {
        // creates the player character and puts it into the list of player
        // controlled party members
        std::shared_ptr<CPrimaryCharacter> player(new CPrimaryCharacter(true));
        m_list_of_characters.push_back(player);
        m_new_game = false;
    }
    
    Result f_status;
    // test loop for combat
    do
    {
        // returns a result from the battle, passing in the class method m_list_of_characters 
        // and the class method, another nested class Game's method get_difficulty which
        // returns the game difficulty returned as an int
        f_status = f_combat_system->PartyVPartyBattle(m_list_of_characters, Difficulty());
    }while(f_status != PLAYER_DEATH);
}