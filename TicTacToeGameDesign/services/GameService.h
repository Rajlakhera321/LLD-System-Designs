#pragma once
#include <bits/stdc++.h>

using namespace std;

class GameService
{
private:
    GameRepository *gameRepo;

public:
    GameService(GameRepository *repo) : gameRepo(repo) {}

    void createGame(int boardSize)
    {
        Game newGame(boardSize);
        gameRepo->addGame(newGame);
    }

    bool makeMoveForPlayer(int gameId, int row, int col)
    {
        auto &games = gameRepo->getGames();
        if (gameId >= 0 && gameId < games.size())
        {
            auto &game = games[gameId];
            auto currentPlayer = game.getCurrentPlayer();
            if (gameRepo->makeMove(gameId, row, col, currentPlayer.getSymbol() == Symbol::X ? 'X' : 'O'))
            {
                // Check for win or draw conditions here and update game status
                return true;
            }
        }
        return false;
    }

    void printBoard(int gameId)
    {
        auto &games = gameRepo->getGames();
        if (gameId >= 0 && gameId < games.size())
        {
            gameRepo->printBoard(gameId);
        }
    }

    void addPlayerToGame(int gameId, string name, Symbol symbol)
    {
        auto &games = gameRepo->getGames();
        if (gameId >= 0 && gameId < games.size())
        {
            gameRepo->addPlayerToGame(gameId, name, symbol);
        }
    }
}