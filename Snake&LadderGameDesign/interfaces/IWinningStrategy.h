#pragma once
#include <bits/stdc++.h>

using namespace std;

class IWinningStrategy
{
public:
    virtual int getNextPosition(int current, int dice, int boardSize) = 0;
    virtual ~IWinningStrategy() {}
};