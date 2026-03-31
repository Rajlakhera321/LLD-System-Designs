#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IWinningStrategies.h"

using namespace std;

class RowColumnDiagonalStrategy : public IWinningStrategies
{
public:
    bool checkWinCondition(Board &board, Move &move)
    {
        int row = move.getRow();
        int col = move.getCol();
        char sym = move.getPlayer().getSymbol() == Symbol::X ? 'X' : 'O';

        auto &grid = board.getBoard();
        int n = board.getSize();

        bool win = true;

        // Row
        for (int c = 0; c < n; c++)
        {
            if (grid[row][c] != sym)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;

        // Column
        win = true;
        for (int r = 0; r < n; r++)
        {
            if (grid[r][col] != sym)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;

        // Diagonal
        if (row == col)
        {
            win = true;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][i] != sym)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                return true;
        }

        // Anti-diagonal
        if (row + col == n - 1)
        {
            win = true;
            for (int i = 0; i < n; i++)
            {
                if (grid[i][n - i - 1] != sym)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                return true;
        }

        return false;
    }
};