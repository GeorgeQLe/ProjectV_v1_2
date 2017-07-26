/*  Copyright 2017 George Le
    Declaration of a supporting base class Subscriber to allow for 
    the use of the observer design pattern
*/
#ifndef SUBSCRIBER_OBSERVER_PATTERN_H
#define SUBSCRIBER_OBSERVER_PATTERN_H

class CSubscriber
{
    public:
    CSubscriber();
    // pure virtual function that must be overloaded
    // NotifyOnEvent executes a reaction to NotifySubscribers
    // function call by the CSubject derived class
    virtual void NotifyOnEvent() = 0;
};

#endif