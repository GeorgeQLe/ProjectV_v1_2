/*  Copyright 2017 George Le
    Declaration of the Inventory class and its member functions
*/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <memory>

template<class TStorageItem>
class CInventory
{
    public:
    CInventory() {}
    
    private:
    // for easy look up store an instance of an item and map to the amount of the item
    std::map<std::shared_ptr<Storage_item>, int> m_inventory;
};

#endif