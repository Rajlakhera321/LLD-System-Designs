#pragma once
#include <bits/stdc++.h>

using namespace std;

class NormalMoveStrategy : public IMoveStrategy
{
public:
    int applyMove(int pos, unique_ptr<Board> board) override
    {
        return board->getNextPosition(pos); // Check for snakes or ladders
    }
};