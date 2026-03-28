#pragma once
#include <bits/stdc++.h>
#include "../enums/gameStatus.h"
#include "../enums/symbol.h"
#include "./Board.h"
#include "./Move.h"
#include "./Players.h"
#include "./IdGenerator.h"

using namespace std;

class Game
{
private:
    int id;
    Board board;
    vector<Players> players;
    GameStatus status;
    int currentPlayerIndex;

public:
    Game(int boardSize)
        : board(boardSize), status(GameStatus::InProgress), currentPlayerIndex(0), id(IdGenerator::generateId()) {}

    void addPlayer(string name, char symbol)
    {
        players.push_back(Player(name, symbol));
    }

    auto getBoard() const
    {
        return board;
    }

    int getId() const
    {
        return id;
    }

    Players &getCurrentPlayer()
    {
        return players[currentPlayerIndex];
    }

    GameStatus getStatus() const
    {
        return status;
    }

    void switchTurn()
    {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }

    void setStatus(GameStatus s)
    {
        status = s;
    }
};