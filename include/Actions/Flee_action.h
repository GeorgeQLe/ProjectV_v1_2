/*  Copyright 2017 George Le
    Declaration of CFleeAction class

*/

#ifndef FLEE_ACTION_H
#define FLEE_ACTION_H

class CFleeAction
{
    public:
    CFleeAction() : can_flee(true) {}
    ~CFleeAction() {}
    
    // function that controls the ingame entity or hostile flee action
    // returns true if flee is successful and false if failed
    bool Flee();
    
    private:
    bool can_flee;
};

#endif