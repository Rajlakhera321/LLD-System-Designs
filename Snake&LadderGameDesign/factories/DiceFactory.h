#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IDiceStrategy.h"
#include "../strategies/diceStrategies/NormalDiceStrategy.h"

using namespace std;

class DiceFactory
{
public:
    unique_ptr<IDiceStrategy> createDiceFactory(const string &strategyType)
    {
        if (strategyType == "Normal")
        {
            return make_unique<NormalDiceStrategy>();
        }
        // Future strategies can be added here
        return nullptr;
    }
};