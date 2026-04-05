#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IMoveStrategy.h"

using namespace std;

class MoveFactory
{
public:
    unique_ptr<IMoveStrategy> createMoveStrategy(const string &strategyType)
    {
        if (strategyType == "Normal")
        {
            return make_unique<NormalMoveStrategy>();
        }
        // Future strategies can be added here
        return nullptr;
    }
};