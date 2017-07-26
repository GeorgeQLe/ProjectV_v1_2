/*  Copyright 2017 George Le
    Declaration of Base_state class and its member functions
*/
#ifndef BASE_STATE_H
#define BASE_STATE_H

// base state class to be overloaded
// templated to make it generic
template<class TEntityType>
class CBaseState
{
    public:
    // displays a little message to let player know the observable state of hostiles
    virtual void Enter(TEntityType*) = 0;
    // actually executes the control of the hostile's actions
    virtual bool Evaluate(TEntityType*) = 0;
    // displays a little message to let player know the change in state of hostiles
    virtual void Exit(TEntityType*) = 0;
    virtual ~CBaseState() {}
};
#endif