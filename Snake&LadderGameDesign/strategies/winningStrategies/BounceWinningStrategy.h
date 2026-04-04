#pragma once
#include <bits/stdc++.h>

using namespace std;

class BounceWinningStrategy : public IWinningStrategy
{
public:
    int getNextPosition(int current, int dice, int boardSize) override
    {
        int next = current + dice;
        if (next > boardSize)
        {
            return boardSize - (next - boardSize); // Bounce back if overshooting
        }
        return next;
    }
};