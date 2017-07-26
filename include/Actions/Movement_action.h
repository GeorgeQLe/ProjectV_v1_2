/*  Copyright 2017 George Le
    Declaration of CMovementAction class and its member functions
*/
#ifndef MOVEMENT_ACTION_H
#define MOVEMENT_ACTION_H

class CMovementAction
{
    public:
    CMovementAction();
    ~CMovementAction();
    
    // function that controls ingame entity or hostile movement
    void Move();
    
    private:
    bool can_move;
};

#endif