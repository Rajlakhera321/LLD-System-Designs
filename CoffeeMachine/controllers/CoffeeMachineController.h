#pragma once
#include "bits/stdc++.h"
#include "../enums/BeverageEnum.h"
#include "../enums/IngredientEnum.h"
#include "../services/BeverageService.h"
#include "../services/InventoryService.h"

using namespace std;

class CoffeeMachineController
{
private:
    BeverageService &beverageService;
    InventoryService &inventoryService;

public:
    CoffeeMachineController(BeverageService &bevService, InventoryService &invService) : beverageService(bevService), inventoryService(invService) {}

    void makeBeverage(BeverageEnum beverageName)
    {
        if (!beverageService.hasBeverage(beverageName))
        {
            cout << "Beverage not available!" << endl;
            return;
        }

        Beverage *bev = beverageService.getBeverage(beverageName);
        for (const auto &ingredient : bev->getIngredients())
        {
            if (!inventoryService.isItemAvailable(ingredient))
            {
                cout << "Ingredient " << static_cast<int>(ingredient) << " is not available!" << endl;
                return;
            }
        }

        for (const auto &ingredient : bev->getIngredients())
        {
            inventoryService.updateInventory(ingredient, -1);
        }

        cout << "Your " << static_cast<int>(beverageName) << " is ready!" << endl;
    }
};