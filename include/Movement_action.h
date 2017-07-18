/*  Copyright 2017 George Le
    Declaration of Movement_action class and its member functions
*/
#ifndef MOVEMENT_ACTION_H
#define MOVEMENT_ACTION_H

class Movement_action
{
    public:
    Movement_action();
    ~Movement_action();
    
    // function that controls ingame entity or hostile movement
    void move();
    
    private:
    bool can_move;
};

#endif