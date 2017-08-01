/*  Copyright 2017 George Le
    
    CGrid<TEntityType> is a templated class that contains a std::map(1) with an integer 
    serving as a key and mapping to a std::vector containing a CGridSquare object, and a 
    std::vector which stores a struct Coordinates which tracks the CGridSquares in the 
    std::map's current location. This class will function as a singleton.
    
(1)
    The std::map<int, std::list <CGridSquare<TEntityType>> m_grid is a member variable of 
    the CGrid class and stores within it as stated above an int key which maps to a list
    storing CGridSquare objects. This member variable will serve as a shrink to fit grid 
    that contains only enough grid squares to hold all the entities on it. Movement by 
    entities within the grid will be tracked by another member variable. Entities can be 
    searched easily by looking up their "y" coordinate which corresponds to the m_grid's 
    key value. Then the CGridSquare will be obtained by its index number that it internally
    stores.

(2)    
    The std::vector<SCoordinate> m_list_of_coordinates is a container of SCoordinates structs
    whose values are recieved from every used gridsquare in the class. This vector allows for 
    easy and fast lookup of the m_grid's list of coordinates. This functionality makes it 
    easier to search for and see if a certain grid coordinate is occupied (if the coordinate
    is not in the vector then it must be empty). The vector should only be modified in 
    conjunction with movement and an element should only be removed when a CGridSquare is
    removed.

    Second attempt at a grid based system :(
*/
#ifndef GRID_H
#define GRID_H

#include <list> // std::list
#include <map> // std::map
#include <memory> // std::shared_ptr
#include <vector> // std::vector

#include "Grid_square.h"

template<class TEntityType>
class CGrid
{
    // Called by the user to recieve an instance of this object.
    static std::shared_ptr<CGrid<TEntityType>> GetInstance();
    
    // Recieves the list of combatants and will initialize the grid to allow for combat
    // on the grid. Four ints passed after the vector of combatants are the dimensions of
    // the grid.
    bool init(std::vector<TEntityType> list_of_combatants, int min_x, int max_x, int min_y, int max_y);
    
    private:
    // default constructor is private because of this object is a singleton
    CGrid();
    
    // For description see above (1)
    std::map<int, std::list<CGridSquare<TEntityType>>> m_grid; // CGridSquare -> Grid_square.h
    
    // For description see above (2)
    std::vector<SCoordinates> m_list_of_coordinates;
};

#include "Grid.imp"

#endif // GRID_H