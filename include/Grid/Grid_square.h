/*  Copyright 2017 George Le
    Declaration of the CGridSquare class and its member functions as well as
    enumerated types DesiredAction and Direction
*/
#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

#include <functional>
#include <list>

#include "Grid/Grid.h"

// A DesiredAction is passed in as a parameter 
// of the NotifyOnEvent function in CGrid
enum DesiredAction
{
    ACTION_NONE,
    ACTION_MOVE,
    ACTION_FIND_CLOSEST,
    ACTION_FIND_WEAKEST,
    ACTION_FIND_FARTHEST
};

// A Direction is passed in as a parameter if the NotifyOnEvent
// has passed in ACTION_MOVE
enum Direction
{ 
    DIRECTION_UNSET,
    DIRECTION_UP,
    DIRECTION_DOWN,
    //DIRECTION_LEFT,
    //DIRECTION_RIGHT
};

struct SCoordinates
{
    SCoordinates(int x, int y) : m_x(x), m_y(y) {}
    
    // x is the index of the vector where the grid square resides
    // used second in CGrid for accessing
    int m_x;
    // y will be used first in accessing the location of a grid square
    // since it will search for a specific row(on y axis) and then
    // move through x to get to a specific column when the grid square
    // sits
    int m_y;
};

// forward declaration of CGrid class
template<class TEntityType>
class CGrid;

template<class TEntityType>
class CGridSquare
{
    public:
    CGridSquare(int x, int y, bool empty);
    
    std::shared_ptr<TEntityType> FindClosestTarget(std::vector<std::shared_ptr<TEntityType>> list_of_targets, bool is_hostile);
    
    // mutator function
    void AddOccupant(TEntityType* new_occupant) { m_reference_to_occupant = new_occupant; }
    void SetNewRow(int new_y) { m_location_in_grid.m_y = new_y; }
    void SetNewColumn(int new_x) { m_location_in_grid.m_x = new_x; }
    
    // adds a subscriber to the list of Observers
    void RegisterSubscribers(std::shared_ptr<CGrid<TEntityType>> new_observer) { m_grid_observer = new_observer; }
    
    // accessor functions
    SCoordinates GetLocation() const { return m_location_in_grid; }
    TEntityType* Occupant() { return m_reference_to_occupant; }
    bool empty() const { return m_empty; }
    
    private:
    // x and y corrdinates tracking the entities position based on the
    // cartesian plane where the player is 
    SCoordinates m_location_in_grid;
    
    // reference to the occupant so that the GridSquare can manipulate it
    std::shared_ptr<TEntityType> m_reference_to_occupant;
    
    // reference to the CGrid object that will observe the CGridSquare,
    // recieve any commands delegated to it by the CGridSquare and 
    // evaulate it
    std::weak_ptr<CGrid<TEntityType>> m_grid_observer;
    
    // Entity passes agruments into these two following variables 
    std::list<DesiredAction> m_list_of_commands;
    Direction m_chosen_direction;
    
    bool m_empty;
};

#include "Grid_square.imp"

#endif