/*  Copyright 2017 George Le
    Declaration of ingame entities' actions
*/
#ifndef ACTIONS_H
#define ACTIONS_H

#include <string>
#include <vector>
#include "attacks.h"

enum Possible_actions { DEFAULT_POSSIBLE_ACTIONS, ATTACKS, ITEMS, MOVEMENT, FLEE};

class Movement_action
{
    public:
    Movement_action() : can_move(true) {}
    // function that controls ingame entity or hostile movement
    void move();
    
    private:
    bool can_move;
};

class Flee_action
{
    public:
    Flee_action() : can_flee(true) {}
    
    // function that controls the ingame entity or hostile flee action
    // returns true if flee is successful and false if failed
    bool flee();
    
    private:
    bool can_flee;
};

class Actions : public Movement_action, public Flee_action
{
    public:
    Actions();
    Possible_actions select_actions();
    void list_possible_actions();
    private:
    List_of_attacks possible_attacks;
    
    std::vector<std::string> list_of_action_names;
    // TO BE DESIGNED
    // class to interact with Inventory in Inventory.h
};

#endif