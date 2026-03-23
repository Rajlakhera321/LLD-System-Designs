#pragma once
#include "../models/Inventory.h"

class InventoryRepository
{
private:
    Inventory inventory;

public:
    Inventory &getInventory()
    {
        return inventory;
    }
};