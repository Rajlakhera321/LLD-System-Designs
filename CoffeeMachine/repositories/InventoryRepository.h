#pragma once
#include <bits/stdc++.h>
#include "../enums/IngredientEnum.h"
#include "../models/Inventory.h"

using namespace std;

class InventoryRepository
{
private:
    unordered_map<IngredientEnum, Inventory> inventory;

public:
    void addInventory(IngredientEnum ingredient, Inventory inv)
    {
        inventory[ingredient] = inv;
    }

    Inventory *getInventory(IngredientEnum ingredient)
    {
        if (!hasInventory(ingredient))
            return NULL;

        return &inventory[ingredient];
    }

    bool hasInventory(IngredientEnum ingredient)
    {
        return inventory.find(ingredient) != inventory.end();
    }

    void updateInventory(IngredientEnum ingredient, int quantity)
    {
        if (hasInventory(ingredient))
        {
            inventory[ingredient].restockIngredient(ingredient, quantity);
        }
        else
        {
            Inventory inv;
            inv.restockIngredient(ingredient, quantity);
            inventory[ingredient] = inv;
        }
    }
};