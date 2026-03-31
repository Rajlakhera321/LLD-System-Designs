#pragma once
#include <bits/stdc++.h>

using namespace std;

class Board
{
private:
    int size;
    vector<vector<char> > board;

public:
    Board(int size) : size(size), board(size, vector<char>(size, ' ')) {}

    int getSize() const
    {
        return size;
    }

    vector<vector<char> > &getBoard()
    {
        return board;
    }

    // ✅ CONST version (for read-only)
    const vector<vector<char> > &getBoard() const
    {
        return board;
    }
};