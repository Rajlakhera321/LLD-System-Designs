#pragma once
#include <bits/stdc++.h>
#include "../models/Board.h"
#include "../models/Move.h"

using namespace std;

class IWinningStrategies
{
public:
    virtual bool checkWinCondition(Board &board, Move &move) = 0;
};