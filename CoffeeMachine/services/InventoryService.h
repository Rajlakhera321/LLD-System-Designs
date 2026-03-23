#pragma once
#include <bits/stdc++.h>
#include "../models/Inventory.h"

class InventoryService
{
public:
    void refill(IngredientEnum ing, int qty)
    {
        Inventory::getInstance().addIngredient(ing, qty);
    }

    bool hasIngredients(const unordered_map<IngredientEnum, int> &recipe)
    {
        return Inventory::getInstance().hasIngredients(recipe);
    }

    void consume(const unordered_map<IngredientEnum, int> &recipe)
    {
        Inventory::getInstance().consumeIngredients(recipe);
    }
};