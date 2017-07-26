/*  Copyright 2017 George Le
    Declaration of CGrid class and its member functions
    
    Declarations:
        -preprocessor directives: 
            -DEFAULT_ROW_AMOUNT = 5, 
            -DEFAULT_MIN_ROW_AMOUNT = 1
        
        -class:
            -CGrid
        
    CGrid is an object that serves as the game map for use in combat only
    underneath the hood implementation as a std::map<int, std::vector<CGridSquare<TEntityType>>>
    where std::map and std::vector are standard library objects, 
    CGridSquare is an object that holds a shared pointer of an TEntityType and,
    TEntityType is a templated class which in this case is a polymorphic CCombatEntity
    
    The use of a vector
*/
#ifndef GRID_H
#define GRID_H

#include <map>
#include <vector>
#include <cmath>
#include <memory>

#include "Grid/Grid_square.h"
#include "Support/subscriber_observer_pattern.h"

#define DEFAULT_ROW_AMOUNT 5
#define DEFAULT_MIN_ROW_AMOUNT 1

template<class TEntityType>
class CGrid : CSubscriber
{
    public:
    CGrid();
    CGrid(int max_rows);
    
    // mutator functions
    void UpdateMaxRows(int new_number_of_rows) { m_max_rows = new_number_of_rows; }
    
    // accessor functions
    int MaxRows() const { return m_max_rows; }
    // uses the distance formula to get the distance between two grid squares
    double GetDistance(const CGridSquare<TEntityType>& first, const CGridSquare<TEntityType>& second);
    // returns a pointer to the current occupant of the grid
    TEntityType* at(int row, int index) { return m_grid.at(row).at(index).occupant(); }
    // moves the calling entity by one row, returns true on success and false on
    // failure to move
    bool Move(std::shared_ptr<TEntityType> calling_entity, int direction);
    
    // overloading the pure virtual function declared in CSubscriber
    virtual void NotifyOnEvent() override;
    
    private:
    // CGrid uses a std::map that stores the entities on it in rows of vectors
    // This feature allows for the CGrid to be easily dynamically expanded and
    // contracted as needed depending on the movement of the entites and the
    // requirements of the game
    std::map<int, std::vector<CGridSquare<TEntityType>>> m_grid;
    
    // variable contains the max amount of rows the map should have
    // a "border" for the CGrid if it is needed
    int m_max_rows;
};

#include "Grid/Grid.imp"

#endif