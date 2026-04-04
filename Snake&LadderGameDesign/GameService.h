#pragma once
#include <bits/stdc++.h>
#include "./interfaces/IDiceStrategy.h"
#include "./models/Board.h"
#include "./models/Player.h"
#include "./enums/GameEnum.h"
#include "./interfaces/IGameObserver.h"
#include "./interfaces/IMoveStrategy.h"
#include "./interfaces/IWinningStrategy.h"

using namespace std;

class GameService
{
private:
    Board *board;
    GameEnum gameState;
    queue<unique_ptr<Player> > players;

    unique_ptr<IDiceStrategy> diceStrategy;
    unique_ptr<IMoveStrategy> moveStrategy;
    unique_ptr<IWinningStrategy> winningStrategy;

    vector<unique_ptr<IGameObserver> > observers;

public:
    GameService(unique_ptr<Board> b,
                queue<unique_ptr<Player> > p,
                unique_ptr<IDiceStrategy> d,
                unique_ptr<IMoveStrategy> m,
                unique_ptr<IWinningStrategy> w) : board(move(b)), players(move(p)), diceStrategy(move(d)), moveStrategy(move(m)), winningStrategy(move(w)), gameState(GameEnum::INPROGRESS)
    {
    }

    void addObserver(unique_ptr<IGameObserver> obs)
    {
        observer.push_back(move(obs));
    }

    void notify(unique_ptr<Move> move)
    {
        for (auto obs : observers)
            obs->onMove(move);
    }

    void play()
    {
        while (gameState == GameEnum::INPROGRESS)
        {
            unique_ptr<Player> currentPlayer = move(players.front()); // For simplicity, we are just using the first player
            players.pop();
            players.push(move(currentPlayer)); // Move the player to the back of the queue

            int diceRoll = diceStrategy->roll();
            int currentPosition = currentPlayer->getPosition();

            int nextPosition = board->getNextPosition(currentPosition, diceRoll, board->getSize()); // Check for snakes or ladders
            next = moveStrategy->applyMove(next, board.get());

            Move move(move(currentPlayer), diceRoll, currentPosition, nextPosition);
            currentPosition->setPosition(nextPosition);

            notify(&move);

            if (nextPosition == board->getSize())
            {
                cout << currentPlayer->getName() << " wins!" << endl;
                gameState = GameEnum::FINISHED;
            }
        }
    }
};