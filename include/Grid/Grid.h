/*  Copyright 2017 George Le
    Declaration of Grid class and its member functions
    
    Declarations:
        -preprocessor directives: DEFAULT_ROW_AMOUNT, DEFAULT_MIN_ROW_AMOUNT
        
        struct:
            -Coordinates
        
        
*/
#ifndef GRID_H
#define GRID_H

#include <map>
#include <vector>
#include <cmath>
#include <memory>

#include "Grid/Grid_square.h"

#define DEFAULT_ROW_AMOUNT 5
#define DEFAULT_MIN_ROW_AMOUNT 1

template<class Entity_type>
class Grid
{
    public:
    Grid();
    Grid(int max_rows);
    
    // mutator functions
    void update_max_rows(int new_number_of_rows) { m_max_rows = new_number_of_rows; }
    
    // accessor functions
    int max_rows() const { return m_max_rows; }
    // uses the distance formula to get the distance between two grid squares
    double get_distance(const Grid_square<Entity_type>& first, const Grid_square<Entity_type>& second);
    // returns a pointer to the current occupant of the grid
    Entity_type* at(int row, int index) { return grid.at(row).at(index).occupant(); }
    // moves the calling entity by one row, returns true on success and false on
    // failure to move
    bool move(std::shared_ptr<Entity_type> calling_entity, int direction);
    
    private:
    // Grid uses a std::map that stores the entities on it in rows of vectors
    // This feature allows for the Grid to be easily dynamically expanded and
    // contracted as needed depending on the movement of the entites and the
    // requirements of the game
    std::map<int, std::vector<Grid_square<Entity_type>>> grid;
    
    // variable contains the max amount of rows the map should have
    // a "border" for the Grid if it is needed
    int m_max_rows;
};

#include "Grid/Grid.imp"

#endif