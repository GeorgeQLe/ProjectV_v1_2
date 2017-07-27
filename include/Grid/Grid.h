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

#define DEFAULT_ROW_AMOUNT 5
#define DEFAULT_MIN_ROW_AMOUNT -5
#define DEFAULT_MAX_COLUMN_AMOUNT 5
#define DEFAULT_MIN_COLUMN_AMOUNT -5

template<class TEntityType>
class CGrid
{
    public:
    CGrid();
    CGrid(int max_rows, int min_rows, int max_column, int min_column);
    
    // mutator functions
    void UpdateMaxRows(int new_number_of_rows) { m_max_rows = new_number_of_rows; }
    
    // accessor functions
    int MaxRows() const { return m_max_rows; }
    
    // uses the distance formula to get the distance between two grid squares
    double GetDistance(const CGridSquare<TEntityType>& first, const CGridSquare<TEntityType>& second);
    
    // returns a pointer to the current occupant of the grid
    // pass in y-value then x-value
    TEntityType* at(int row, int index) { return m_grid.at(row).at(index).occupant(); }
    
    // two functions to recieve and evaluate commands given by the member CGridSquare objects
    void NotifyOnEvent(DesiredAction action, TEntityType entity, int x, int y);
    
    // this function specifically controls movement
    bool NotifyOnEvent(DesiredAction action, Direction direction, int x, int y);
    
    // moves the calling entity by one row, returns true on success and false on
    // failure to move
    bool Move(CGridSquare<TEntityType> calling_entity, Direction new_direction);
    
    private:
    // CGrid uses a std::map that stores the entities on it in rows of vectors
    // This feature allows for the CGrid to be easily dynamically expanded and
    // contracted as needed depending on the movement of the entites and the
    // requirements of the game
    std::map<int, std::vector<CGridSquare<TEntityType>>> m_grid;
    
    // the following variables are not unsigned because the CGrid should be able
    // to have characters moving into the negative rows since the battle starts
    // at (0,0) and the bottom character can retreat
    // variable contains the max amount of rows the map should have
    // a "border" for the CGrid if it is needed
    int m_max_rows;
    // min rows is the bottom border
    int m_min_rows;
    // max column is the right border
    int m_max_column;
    // min column is the left border
    // in current form, should never be reached since entities just pushback
    // on the right side when moving between rows and no interaction with
    // left or right movement
    int m_min_column;
};

#include "Grid/Grid.imp"

#endif