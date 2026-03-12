#pragma once
#include <bits/stdc++.h>
#include "../enums/BeverageEnum.h"
#include "../enums/IngredientEnum.h"

using namespace std;

class Beverage
{
private:
    BeverageEnum name;
    unordered_set<IngredientEnum> ingredients;

public:
    Beverage(BeverageEnum name, unordered_set<IngredientEnum> ingredients) : name(name), ingredients(ingredients) {}

    BeverageEnum getName() const
    {
        return name;
    }

    unordered_set<IngredientEnum> getIngredients() const
    {
        return ingredients;
    }

    void addIngredient(IngredientEnum ingredient)
    {
        ingredients.insert(ingredient);
    }

    void removeIngredient(IngredientEnum ingredient)
    {
        ingredients.erase(ingredient);
    }
};