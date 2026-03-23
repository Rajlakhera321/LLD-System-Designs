#pragma once
#include <bits/stdc++.h>
#include "../services/BeverageService.h"
#include "../services/InventoryService.h"

using namespace std;

class CoffeeMachineController
{
private:
    BeverageService beverageService;
    InventoryService inventoryService;

public:
    void makeBeverage(BeverageEnum type)
    {

        auto beverage = beverageService.createBeverage(type);

        if (!beverage)
        {
            cout << "Invalid beverage\n";
            return;
        }

        auto recipe = beverage->getRecipe();

        if (!inventoryService.hasIngredients(recipe))
        {
            cout << "Insufficient ingredients\n";
            return;
        }

        inventoryService.consume(recipe);

        cout << beverage->getName() << " is ready!\n";
    }

    void refill(IngredientEnum ing, int qty)
    {
        inventoryService.refill(ing, qty);
    }
};