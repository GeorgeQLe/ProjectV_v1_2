/*  Copyright 2016 George Le
    This file contains the definitions of the member 
    functions of the classes declared and defined in scene.h
*/
#include <iostream>
#include <fstream>
#include "scene.h"

void Game_script::load_game_script(const std::string& file_name)
{
    using std::string;
    using std::ifstream;

    ifstream file(file_name);
    
    if(file.is_open())
    {
        string temp = " ", stopping_condition = " ", scene_name = " ";
        bool first_time = true;

        getline(file, scene_name);
        getline(file, stopping_condition);
        
        while(!file.eof())
        {
            while(temp.compare(stopping_condition) != 0 || first_time)
            {
                getline(file, temp);
                if(first_time)
                {
                    m_game_script.emplace(scene_name, temp);
                    m_game_script.at(scene_name)+='\n';
                    first_time = false;
                }
                else if(temp.empty())
                {
                    m_game_script.at(scene_name)+='\n';
                }
                else if(temp != stopping_condition)
                {
                    m_game_script.at(scene_name)+=temp;
                    m_game_script.at(scene_name)+='\n';
                }
            }
            first_time = true;
            getline(file,temp);
            while(temp.empty())
            {
                getline(file, temp);
                scene_name = temp;
            }
            getline(file,temp);
            stopping_condition = temp;
            temp = " ";
        }
    }
    
    file.close();
}

bool Narrative_scene::check_requested_event(const std::string& Requested_event, const Game_script& script)
{
    return static_cast<bool>(script.m_game_script.count(Requested_event));    
}

void Narrative_scene::read_from_script(const std::string& Event_name)
{
    Game_script* script;
    *script = get_instance(m_file_name);
    if(check_requested_event(Event_name, *script))
    {
        std::cout << script->m_game_script.at(Event_name);
    }
    else
    {
        std::cout << "Programmer done screwed up... tried to pass in event " << Event_name << std::endl;
        std::cout << "Check game script or the event name and resolve the issue." << std::endl;
    }
}