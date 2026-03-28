#pragma once
#include <bits/stdc++.h>

using namespace std;

class GameController
{
private:
    GameService *gameService;

public:
    GameController(GameService *service) : gameService(service) {}

    void createGame(int boardSize)
    {
        gameService->createGame(boardSize);
    }

    bool makeMoveForPlayer(int gameId, int row, int col)
    {
        return gameService->makeMoveForPlayer(gameId, row, col);
    }

    void printBoard(int gameId)
    {
        gameService->printBoard(gameId);
    }

    void addPlayerToGame(int gameId, string name, Symbol symbol)
    {
        gameService->addPlayerToGame(gameId, name, symbol);
    }
}