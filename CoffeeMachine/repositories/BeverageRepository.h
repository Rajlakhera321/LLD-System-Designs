#pragma once
#include <bits/stdc++.h>
#include "../enums/BeverageEnum.h"
#include "../models/Beverage.h"

using namespace std;

class BeverageRepository
{
private:
    vector<Beverage *> beverages;

public:
    void addBeverage(Beverage *bev)
    {
        beverages.push_back(bev);
    }

    Beverage *getBeverage(BeverageEnum name)
    {
        for (auto bev : beverages)
        {
            if (bev->getName() == name)
                return bev;
        }
        return nullptr;
    }

    bool hasBeverage(BeverageEnum name)
    {
        return getBeverage(name) != nullptr;
    }

    void addIngredientToBeverage(BeverageEnum beverage, IngredientEnum ingredient)
    {
        if (hasBeverage(beverage))
        {
            getBeverage(beverage)->addIngredient(ingredient);
        }
    }

    void removeIngredientFromBeverage(BeverageEnum beverage, IngredientEnum ingredient)
    {
        if (hasBeverage(beverage))
        {
            getBeverage(beverage)->removeIngredient(ingredient);
        }
    }
};