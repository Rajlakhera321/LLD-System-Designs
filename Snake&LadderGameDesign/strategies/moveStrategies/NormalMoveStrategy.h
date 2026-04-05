#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IMoveStrategy.h"

using namespace std;

class NormalMoveStrategy : public IMoveStrategy
{
public:
    int applyMove(int pos, Board *board) override
    {
        return board->getNextPosition(pos); // Check for snakes or ladders
    }
};