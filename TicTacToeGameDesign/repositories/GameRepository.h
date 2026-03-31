#pragma once
#include <bits/stdc++.h>
#include "../enums/Symbol.h"
#include "../models/Players.h"
#include "../models/Game.h"

using namespace std;

class GameRepository
{
private:
    vector<Game> games;

public:
    void addGame(const Game &game)
    {
        games.push_back(game);
    }

    bool makeMove(int id, int row, int col, char symbol)
    {
        auto &boardObj = games[id].getBoard();
        auto &board = boardObj.getBoard();
        int size = boardObj.getSize();
        if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == ' ')
        {
            board[row][col] = symbol;
            return true;
        }

        return false;
    }

    void printBoard(int id) const
    {
        cout << "\n";
        auto &board = games[id].getBoard().getBoard();
        for (auto &row : board)
        {
            for (auto &cell : row)
            {
                cout << (cell == ' ' ? '-' : cell) << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void addPlayerToGame(int id, string name, Symbol symbol)
    {
        games[id].addPlayer(name, symbol);
    }

    vector<Game> &getGames()
    {
        return games;
    }

    bool isDraw(int id)
    {
        auto &board = games[id].getBoard().getBoard();
        // auto &grid = board.getGrid();
        for (auto &row : board)
        {
            for (auto &cell : row)
            {
                if (cell == ' ')
                    return false;
            }
        }
        return true;
    }
};