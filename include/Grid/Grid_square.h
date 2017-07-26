/*  Copyright 2017 George Le
    Declaration of the CGridSquare class and its member functions as well as
    enumerated types DesiredAction and Direction
*/
#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

#include "Support/subject_observer_pattern.h"

// A DesiredAction is passed in as a parameter 
// of the NotifyOnEvent function in CGrid
enum class DesiredAction
{
    ACTION_NONE,
    ACTION_MOVE,
    ACTION_FIND_CLOSEST,
    ACTION_FIND_WEAKEST,
    ACTION_FIND_FARTHEST
};

// A Direction is passed in as a parameter if the NotifyOnEvent
// has passed in ACTION_MOVE
enum class Direction
{ 
    DIRECTION_UNSET,
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

struct SCoordinates
{
    SCoordinates(int x, int y) : m_x(x), m_y(y) {}
    
    int m_x;
    int m_y;
};

template<class TEntityType>
class CGridSquare : public CSubject
{
    public:
    CGridSquare(int x, int y, bool empty);
    
    std::shared_ptr<TEntityType> FindClosestTarget(std::vector<std::shared_ptr<TEntityType>> list_of_targets, bool is_hostile);
    
    // mutator function
    void AddOccupant(TEntityType* new_occupant) { m_reference_to_occupant = new_occupant; }
    
    // accessor functions
    SCoordinates GetLocation() const { return m_location_in_grid; }
    TEntityType* Occupant() { return m_reference_to_occupant; }
    bool empty() const { return m_empty; }
    
    private:
    SCoordinates m_location_in_grid;
    
    std::shared_ptr<TEntityType> m_reference_to_occupant;
    
    bool m_empty;
};

#include "Grid_square.imp"

#endif