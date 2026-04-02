#pragma once
#include <bits/stdc++.h>
#include "./Cell.h"

using namespace std;

class Board
{
private:
    int size;
    vector<Cell *> cells;

public:
    Board(int s) : size(s)
    {
        cells.resize(s + 1);
        for (int i = 0; i <= s; i++)
        {
            cells[i] = new Cell(i);
        }
    }

    void addJump(int start, int end)
    {
        cells[start]->setJump(new Jump(start, end));
    }

    int getSize() const { return size; }
    vector<Cell *> getCells() const { return cells; }

    int getNextPosition(int currentPosition)
    {
        if (cells[currentPosition] != NULL)
            return cells[currentPosition]->getJump() != NULL ? cells[currentPosition]->getJump()->getEnd() : currentPosition;

        return currentPosition;
    }
};