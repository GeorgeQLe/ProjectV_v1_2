/*  Copyright 2017 George Le
    
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

#define DEFAULT_ROW_AMOUNT 5
#define DEFAULT_MIN_ROW_AMOUNT 1

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
    Entity_type* occupant() { return m_reference_to_occupant; }
    bool empty() const { return m_empty; }
    
    private:
    Coordinates m_location_in_grid;
    
    std::shared_ptr<Entity_type> m_reference_to_occupant;
    
    bool m_empty;
};

template<class Entity_type, class Compare = std::equal_to<Entity_type>>
class Grid
{
    public:
    Grid() : m_max_rows(DEFAULT_ROW_AMOUNT)
    {
        // filling up the grid to have at least one square for all the rows
        int y = 0;
        // set up at least 2 grid squares for two opponents squaring off in close range
        // and in front of each other
        for(int x = 0; x < 2; ++x)
        {
            // creates a grid square at position (0,1) and then iterates the x value
            Grid_square<Entity_type> grid_square(x, y, true);
            grid[x].push_back(grid_square);
        }
    }
    Grid(int max_rows) : m_max_rows(max_rows)
    {
        // filling up the grid to have at least one square for all the rows
        int y = 0;
        // set up at least 2 grid squares for two opponents squaring off in close range
        // and in front of each other
        for(int x = 0; x < 2; ++x)
        {
            // creates a grid square at position (0,1) and then iterates the x value
            Grid_square<Entity_type> grid_square(x, y, true);
            grid[x].push_back(grid_square);
        }
    }
    
    // mutator functions
    void update_max_rows(int new_number_of_rows) { m_max_rows = new_number_of_rows; }
    
    // accessor functions
    int max_rows() const { return m_max_rows; }
    // uses the distance formula to get the distance between two grid squares
    double get_distance(const Grid_square<Entity_type>& first, const Grid_square<Entity_type>& second)
    {
        return sqrt(pow((static_cast<double>(second.get_location().m_x) - static_cast<double>(first.get_location().m_x)), 2.0) + 
                    pow((static_cast<double>(second.get_location().m_y) - static_cast<double>(first.get_location().m_y)), 2.0));
    }

    // returns a pointer to the current occupant of the grid
    Entity_type* at(int row, int index) { return grid.at(row).at(index).occupant(); }
    // moves the calling entity by one row, returns true on success and false on
    // failure to move
    bool move(std::shared_ptr<Entity_type> calling_entity, int direction, const Compare& comp = Compare())
    {
        
        if(true)
        {
            return true;
        }
        
        // if it can't verify that it is the correct calling entity and if the move is invalid
        // function will return false
        return false;
    }
    
    private:
    std::map<int, std::vector<Grid_square<Entity_type>>> grid;
    
    int m_max_rows;
};

#endif