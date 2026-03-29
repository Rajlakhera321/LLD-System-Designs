#pragma once
#include <bits/stdc++.h>

using namespace std;

class GameController
{
private:
    GameService *gameService;
    Game &game;

public:
    GameController(GameService *service, Game &g) : gameService(service), game(g) {}

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

    void startGame()
    {
        while (game.getStatus() == GameStatus::InProgress)
        {
            printBoard(game.getId());
            Players &currentPlayer = game.getCurrentPlayer();
            cout << "It's " << currentPlayer.getName() << "'s turn (" << currentPlayer.getSymbol() << ").\n";
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (!makeMoveForPlayer(game.getId(), row, col))
            {
                cout << "❌ Invalid move! Try again.\n";
            }
        }
    }
};