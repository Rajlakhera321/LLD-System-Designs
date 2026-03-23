#pragma once
#include "../interfaces/IPreparation.h"
#include "../enums/IngredientEnum.h"

class LatteStrategy : public IPreparation
{
public:
    unordered_map<IngredientEnum, int> getRecipe() override
    {
        return {
            {IngredientEnum::CoffeeBeans, 10},
            {IngredientEnum::Milk, 30},
            {IngredientEnum::Water, 40}};
    }

    string getName() override
    {
        return "Latte";
    }
};