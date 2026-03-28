#pragma once
#include <bits/stdc++.h>
#include "./Players.h"

using namespace std;

class Move
{
private:
    int row;
    int col;
    Players player;

public:
    Move(int row, int col, Players player) : row(row), col(col), player(player) {}

    int getRow() const
    {
        return row;
    }

    int getCol() const
    {
        return col;
    }

    Players getPlayer() const
    {
        return player;
    }
};