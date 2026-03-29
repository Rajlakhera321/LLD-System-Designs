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
        Symbol symbol = move.getSymbol();

        // Check the row
        bool win = true;
        for (int c = 0; c < board.getSize(); c++)
        {
            if (board[row][c] != symbol)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;

        // Check the column
        win = true;
        for (int r = 0; r < board.getSize(); r++)
        {
            if (board[r][col] != symbol)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;

        // Check the main diagonal
        if (row == col)
        {
            win = true;
            for (int i = 0; i < board.getSize(); i++)
            {
                if (board[i][i] != symbol)
                {
                    win = false;
                    break;
                }
            }
            if (win)
                return true;
        }

        // Check the anti-diagonal
        if (row + col == board.getSize() - 1)
        {
            win = true;
            for (int i = 0; i < board.getSize(); i++)
            {
                if (board[i][board.getSize() - 1 - i] != symbol)
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