/*  Copyright 2017 George Le
    Definition of the member functions of the CSubject class
*/
#include "Support/subject_observer_pattern.h"

CSubject::CSubject()
{
    // Empty constructor
}

void CSubject::RegisterSubscribers(CSubscriber& new_subscriber)
{
    m_observers.push_back(new_subscriber);
}

void CSubject::NotifySubscribers()
{
    for(CSubscriber& subscribers : m_observers)
    {
        subscribers.NotifyOnEvent();
    }
}