#include <iostream>
#include <fstream>
#include "Diadal.h"
#include "support.h"

Diadal::Diadal() : standard_game(1, EASY, "Diadal"), m_game_running(true), m_new_game(true), m_number_of_party_members(0) 
{
    std::ifstream file("Diadal_text_File.txt");
    if(file.is_open())
    {
        std::string line(""), second_line("");
        while(getline(file, line)) // Receives the flags for the file names (ALL CAPS)
        {
            while(getline(file, second_line)) // Receives the actual file name for the script to use
            {
                m_script_names.at(line) = second_line;
            }
        }
    }
}

void Diadal::game_loop()
{
    //put here just to test
    if(m_new_game)
    {
        Primary_character* player = new Primary_character(m_script_names.at("CHARACTER CREATION"));
        m_list_of_characters.emplace(++m_number_of_party_members, player);
        m_new_game = false;
    }
    else
    {
        //load saved game    
    }
    
    //game loop
    while(m_game_running)
    {
        std::cout << "Select an option:\n";
        std::cout << "1. New game\n";
        std::cout << "2. Start from game checkpoint\n";
        std::cout << "3. Back\n" << std::endl;
        int choice = get_number_from_user(1, 3);
        
        if(choice == 1)
        {   
            new_game();
        }
        else if(choice == 3)
        {
            m_game_running = game_menu();
        }
    }
}

bool Diadal::game_menu()
{
    if(standard_game.game_main_menu())
    {
        m_game_running = true;
    }
    else
    {
        m_game_running = false;
    }
    
    return m_game_running;
}

void Diadal::new_game()
{
    // TO BE DESIGNED
}