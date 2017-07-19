#ifndef GRID_SQUARE_H
#define GRID_SQUARE_H

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


#endif