/*  Copyright 2017 George Le
    Declaration of Flee_action class

*/

#ifndef FLEE_ACTION_H
#define FLEE_ACTION_H

class Flee_action
{
    public:
    Flee_action() : can_flee(true) {}
    ~Flee_action() {}
    
    // function that controls the ingame entity or hostile flee action
    // returns true if flee is successful and false if failed
    bool flee();
    
    private:
    bool can_flee;
};

#endif