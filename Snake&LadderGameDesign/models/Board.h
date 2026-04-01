#pragma once
#include <bits/stdc++.h>

class Board
{
private:
    int size;
    vector<*Cell> cells;

public:
    Board(int s) : size(s), cells(s + 1)
    {
    }

    void addJump(Jump *j)
    {
        cells
    }

    int getSize() const { return size; }
    vector<*Cell> getCells() const { return cells; }
};