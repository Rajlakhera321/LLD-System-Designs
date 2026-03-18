#pragma once
#include <bits/stdc++.h>
#include "../repositories/InventoryRepository.h"

using namespace std;

class InventoryService
{
private:
    InventoryRepository repository;

public:
    bool isItemAvailable(const IngredientEnum &item)
    {
        return repository.hasInventory(item);
    };
    void updateInventory(const IngredientEnum &item, int quantity)
    {
        repository.updateInventory(item, quantity);
    };

    Inventory *getInventory(const IngredientEnum &item)
    {
        return repository.getInventory(item);
    }

    void addInventory(const IngredientEnum &item, Inventory inv)
    {
        repository.addInventory(item, inv);
    }
};