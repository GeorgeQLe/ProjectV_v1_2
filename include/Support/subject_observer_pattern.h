/*  Copyright 2017 George Le
    Declaration of the base class CSubject to be used in conjunction with the CSubscriber class
    to allow for the observer design pattern
*/
#ifndef SUBJECT_OBSERVER_PATTERN_H
#define SUBJECT_OBSERVER_PATTERN_H

#include <functional>
#include <vector>

#include "Support/subscriber_observer_pattern.h"

class CSubject
{
    public:
    // Empty default constructor
    CSubject();
    
    // Add new subscribers to be included in the notification of
    // an event occuring to this CSubject class
    void RegisterSubscribers(CSubscriber& new_subscriber);
    
    // Notify all subscribers that an event has occured
    void NotifySubscribers();
    
    private:
    std::vector<std::reference_wrapper<CSubscriber>> m_observers;
};

#endif