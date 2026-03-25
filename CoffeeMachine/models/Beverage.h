#pragma once
#include <memory>
#include <iostream>
#include <bits/stdc++.h>
#include "../interfaces/IPreparation.h"

using namespace std;

class Beverage
{
private:
    unique_ptr<IPreparation> strategy;

public:
    Beverage(unique_ptr<IPreparation> strategy)
        : strategy(move(strategy)) {}

    unordered_map<IngredientEnum, int> getRecipe()
    {
        return strategy->getRecipe();
    }

    string getName()
    {
        return strategy->getName();
    }
};