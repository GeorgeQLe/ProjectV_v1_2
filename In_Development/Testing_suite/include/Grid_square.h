/*  Copyright 2017 George Le
    
    Declaration of struct SCoordinate and class CGridSquare
    
    The struct SCoordinate is a plain old data structure that stores the x 
    and y coordinate of the CGridSquare and holds the index of the CGridSquare 
    in the CGrid's vector, set to -1 by default if not used.

    
*/
#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

struct SCoordinates
{
    SCoordinates(int new_x, int new_y) : x(new_x), y(new_y), index(-1) {}
    SCoordinates(int new_x, int new_y, int new_index) : x(new_x), y(new_y), index(new_index) {}
    
    int x; 
    int y;
    int index;
};

template<class TEntityType>
class CGridSquare
{
    public:
    // default constructor
    CGridSquare();
    // simple constructor 
    CGridSquare(int x, int y, std::shared_ptr<TEntityType> new_occupant);
    
    // accessor function
    // returns the true column/x coordinate of the occupant in the virtual space of the grid
    int get_x() const { return m_coordinates.x; }
    // returns the "row" that the occupant sits in the grid, often used for easy
    // lookup for neighbors in the same row horizontally
    int get_y() const { return m_coordinates.y; }
    // returns the "column" that the occupant sits in the "row"(int key value/"y" value) of the grid
    // used for easy lookup in the std::vector stored by the CGrid's std::map<int, std::vector...>
    int get_index_in_grid() const { return m_coordinates.index(); }
    
    // mutator functions
    void update_x(int new_x) { m_coordinates.x = new_x; }
    void update_y(int new_y) { m_coordinates.y = new_y; }
    void update_index(int new_index) { m_coordinates.index = new_index; }
    
    private:
    // Stores the x and y coordinates of this object and the index of the list
    SCoordinates m_coordinates;
    
    // weak reference to the current occupant of this object
    std::weak_ptr<TEntityType> m_occupant;
    
    bool m_IsEmpty;
};

#include "Grid_square.imp"

#endif // GRID_SQUARE_H