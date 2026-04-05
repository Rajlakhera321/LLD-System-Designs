#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IWinningStrategy.h"
#include "../strategies/winningStrategies/ExactWinningStrategy.h"
#include "../strategies/winningStrategies/BounceWinningStrategy.h"

using namespace std;

class WinningFactory
{
public:
    unique_ptr<IWinningStrategy> createWinningStrategy(const string &strategyType)
    {
        if (strategyType == "Exact")
        {
            return make_unique<ExactWinningStrategy>();
        }
        else if (strategyType == "Bounce")
        {
            return make_unique<BounceWinningStrategy>();
        }
        // Future strategies can be added here
        return nullptr;
    }
};