#pragma once
#include <bits/stdc++.h>
#include "./Cell.h"

using namespace std;

class Board
{
private:
    int size;
    vector<unique_ptr<Cell> > cells;

public:
    Board(int s) : size(s)
    {
        cells.resize(s + 1);
        for (int i = 0; i <= s; i++)
        {
            cells[i] = make_unique<Cell>(i);
        }
    }

    void addJump(int start, int end)
    {
        cells[start]->setJump(make_unique<Jump>(start, end));
    }

    int getSize() const { return size; }
    const vector<unique_ptr<Cell> > &getCells() const { return cells; }

    int getNextPosition(int pos)
    {
        if (cells[pos]->getJump())
            return cells[pos]->getJump()->getEnd();

        return pos;
    }
};