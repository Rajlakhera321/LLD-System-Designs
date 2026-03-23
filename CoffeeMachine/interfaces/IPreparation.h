#pragma once
#include <bits/stdc++.h>
#include "../enums/IngredientEnum.h"

using namespace std;

class IPreparation
{
public:
    virtual unordered_map<IngredientEnum, int> getRecipe() = 0;
    virtual string getName() = 0;
    virtual ~IPreparation() {};
};