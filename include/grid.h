/*  Copyright 2017 George Le

*/
#ifndef GRID_H
#define GRID_H

#include <map>
#include <vector>
#include <cmath>
#include "grid.h"

#define DEFAULT_ROW_AMOUNT 5
#define DEFAULT_MIN_ROW_AMOUNT 2

struct Coordinates
{
    Coordinates(int x, int y) : m_x(x), m_y(y) {}
    
    int m_x;
    int m_y;
};

template<class Entity_type>
class Grid_square
{
    public:
    Grid_square(int x, int y, bool empty) : m_location_in_grid(x, y), m_reference_to_occupant(nullptr), m_empty(empty) {}
    
    // mutator function
    void add_occupant(Entity_type* new_occupant) { m_reference_to_occupant = new_occupant; }
    
    // accessor functions
    Coordinates get_location() const { return m_location_in_grid; }
    bool empty() const { return m_empty; }
    Entity_type* occupant() { return m_reference_to_occupant; }
    
    private:
    Coordinates m_location_in_grid;
    
    Entity_type* m_reference_to_occupant;
    
    bool m_empty;
};

template<class Entity_type>
class Grid
{
    public:
    Grid() : m_max_rows(DEFAULT_ROW_AMOUNT), m_min_rows(DEFAULT_MIN_ROW_AMOUNT) {}
    
    // uses the distance formula to get the distance between two grid squares
    double get_distance(const Grid_square<Entity_type>& first, const Grid_square<Entity_type>& second);
    
    // returns a pointer to the current occupant of the grid
    Entity_type* at(int index) { return grid.at(index).occupant(); }
    
    // mutator functions
    void update_max_rows(int new_number_of_rows) { m_max_rows = new_number_of_rows; }
    void update_min_rows(int new_number_of_rows) { m_min_rows = new_number_of_rows; }
    
    // accessor functions
    int max_rows() const { return m_max_rows; }
    int min_rows() const { return m_min_rows; }
    
    private:
    std::map<int, Grid_square<Entity_type>> grid;
    
    int m_max_rows;
    int m_min_rows;
};

#include "grid.imp"

#endif