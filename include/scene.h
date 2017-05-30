/*  Copyright 2016 George Le
    Provides the implementation of a narrative scene class that takes in a .txt file and saves it as a game
    script. Provides controlled global access to the game script that is saved as a map with portions of the script being
    saved at specified key values
    
    Designed using the observer pattern
    
    Declaration:
        Classes:
            -Game_script
            -Narrative_scene
*/
#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <map>

class Game_script
{
    public:
    // default constructor <- should never happen throughout the game since
    // Narrative scene should be the only class where Game_script 
    Game_script() {}
    Game_script(const std::string& file_name) { load_game_script(file_name); }
    void load_game_script(const std::string& file_name);
    //the actual script of the game held in a std::map object
    std::map<std::string, std::string> m_game_script;
};

class Narrative_scene //Observer ->children are inheriting "Subjects" to the parent class Narrative_scene 
                      //           they override the on_Read method to allow for user interaction with the
                      //           game script
{
    public:
    Narrative_scene(const std::string& file_name) : m_file_name(file_name) {}
    
    protected:
    virtual void on_Read(const std::string& Event_name) = 0;
    void read_from_script(const std::string& Event_name);
    
    private:
    // using the singleton design pattern, create one instance of the game script
    // and pass it to the child classes.
    static Game_script get_instance(const std::string file_name)
    {
        static Game_script singleton = Game_script(file_name);
        return singleton;
    }
    // checks if the requested event is in the game script, should only be called in the
    // read from script function
    bool check_requested_event(const std::string& Requested_event, const Game_script& script);
    
    // file name passed in by every inheriting class, allows for many different documents
    std::string m_file_name;
};

#endif //SCENE_H