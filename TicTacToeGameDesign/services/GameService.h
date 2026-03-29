#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IWinningStrategies.h"
#include "../repositories/GameRepository.h"
#include "../models/Game.h"
#include "../models/Players.h"
#include "../models/Move.h"
#include "../enums/Symbol.h"
#include "../enums/GameStatus.h"

using namespace std;

class GameService
{
private:
    GameRepository *gameRepo;
    IWinningStrategies *strategy;

public:
    GameService(GameRepository *repo, IWinningStrategies *winningStrategy) : gameRepo(repo), strategy(winningStrategy) {}

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
            Players &currentPlayer = game.getCurrentPlayer();
            if (!gameRepo->makeMove(gameId, row, col, currentPlayer.getSymbol() == Symbol::X ? 'X' : 'O'))
            {
                cout << "❌ Invalid move! Try again.\n";
                return false;
            }

            Move move(row, col, currentPlayer);

            if (strategy->checkWinCondition(game.getBoard(), move))
            {
                gameRepo->printBoard(gameId);
                cout << "🏆 " << player.name << " wins!\n";
                game.setStatus(GameStatus::WIN);
                return;
            }

            if (gameRepo->isDraw())
            {
                gameRepo->printBoard(gameId);
                cout << "🤝 It's a draw!\n";
                game.setStatus(GameStatus::DRAW);
                return;
            }

            game.switchTurn();

            return true;
        }
        return false;
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