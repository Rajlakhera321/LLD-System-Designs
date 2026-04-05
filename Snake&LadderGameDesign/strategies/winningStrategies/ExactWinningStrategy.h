#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IWinningStrategy.h"

using namespace std;

class ExactWinningStrategy : public IWinningStrategy
{
public:
    int getNextPosition(int current, int dice, int boardSize) override
    {
        if (current + dice > boardSize)
        {
            return current; // Stay in the same position if overshooting
        }
        return current + dice;
    }
};