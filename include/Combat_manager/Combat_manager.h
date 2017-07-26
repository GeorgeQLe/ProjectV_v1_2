/*  Copyright 2017 George Le
    Declaraion of the CCombatManager class which implements a turn-based combat system between Primary characters and 
    internally stored created hostiles
    
    CCombatManager is designed as a singleton
*/

#ifndef COMBAT_H
#define COMBAT_H

#include <memory>
#include <vector>
#include <map>
#include "Entity/Primary_character.h"
#include "Entity/Hostile.h"

enum Result { NOT_STARTED = -1, FIGHTING, PLAYER_DEATH, PLAYER_VICTORY, TIE, POTENTIAL_PLAYER_WIPE, POTENTIAL_HOSTILE_WIPE};

class CCombatManager
{
    public:
    // Function to allow for game to receive an instance of the CCombatManager
    static std::shared_ptr<CCombatManager> GetInstance()
    {
        static std::shared_ptr<CCombatManager> instance(new CCombatManager);
        return instance;
    }
    
    // merge the two vectors of list of player characters and hostiles into a third vector turn order and
    // combat will affect this vector which contains pointers to the original party characters
    void CreateTurnOrder(const std::vector<std::shared_ptr<CPrimaryCharacter>>& list_of_characters, 
                    const std::vector<std::shared_ptr<CHostile>>& list_of_hostiles);
    
    // Function that plays out one turn of combat
    Result SingleTurn(unsigned int number_of_player_characters, unsigned int number_of_hostiles);
    
    // experimental battle with a similar xcom style with elements of combat in pokemon  
    Result PartyVPartyBattle(std::vector<std::shared_ptr<CPrimaryCharacter>>& list_of_characters, int enum_difficult_converted_to_int);
    
    // two following functions check to see if the potential player or hostile wipes are a reality or not
    bool CheckPlayerHealths(std::vector<std::shared_ptr<CPrimaryCharacter>> list_of_characters);
    bool CheckHostileHealths(std::vector<std::shared_ptr<CHostile>> list_of_hostiles);
    
    private:
    // constructor is private bc the object is a singleton
    CCombatManager();
    
    // standard turn order used for combat
    std::vector<std::shared_ptr<CCombatEntity>> m_turn_order;
    
    // temporary turn order used for any modifications to the main turn order
    // such as temporary speed modifications
    std::vector<std::shared_ptr<CCombatEntity>> m_temp_turn_order;
    
    // object pool to store hostiles so you don't have to continuously create more and more hostile objects
    // stores multiple vectors that hold each "wave" of hostile enemies
    // uses a std::map
    std::map<int, std::vector<std::shared_ptr<CHostile>>> m_object_pool;
    
    // a grid object that serves as the game map
    // underneath the hood implementation as a std::map<int, std::vector<CGridSquare<Entity_type>>>
    // where std::map and std::vector are standard library objects, 
    // CGridSquare is an object that holds a shared pointer of an TEntityType,
    // TEntityType is a templated class which in this case is a polymorphic CCombatEntity
    CGrid<CCombatEntity> m_game_map;
};

#endif