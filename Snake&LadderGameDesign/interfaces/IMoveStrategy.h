#pragma once
#include <bits/stdc++.h>
#include "../models/Board.h"

using namespace std;

class IMoveStrategy
{
public:
    virtual int applyMove(int pos, Board *board) = 0;
    virtual ~IMoveStrategy() {}
};