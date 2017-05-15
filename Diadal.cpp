#include <iostream>
#include "Diadal.h"
#include "support.h"

void Diadal::game_loop()
{
    //put here just to test
    if(m_new_game)
    {
        Primary_character* player = new Primary_character(script_name);
        list_of_characters.emplace(++number_of_party_members, player);
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