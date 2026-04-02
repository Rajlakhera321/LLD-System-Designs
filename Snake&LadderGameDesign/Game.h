#pragma once
#include <bits/stdc++.h>
#include "interfaces/IDiceStrategy.h"
#include "./models/Board.h"
#include "./models/Player.h"

using namespace std;

class Game
{
private:
    Board *board;
    queue<Player *> players;
    IDiceStrategy *diceStrategy;

public:
    Game(Board *b, queue<Player *> p, IDiceStrategy *ds) : board(b), players(p), diceStrategy(ds) {}

    void play()
    {
        while (true)
        {
            Player *currentPlayer = players.front(); // For simplicity, we are just using the first player
            players.pop();
            players.push(currentPlayer); // Move the player to the back of the queue

            int diceRoll = diceStrategy->roll();
            int newPosition = currentPlayer->getPosition() + diceRoll;

            if (newPosition > board->getSize())
            {
                newPosition = board->getSize() - (newPosition - board->getSize()); // Bounce back if overshooting
            }

            newPosition = board->getNextPosition(newPosition); // Check for snakes or ladders

            currentPlayer->setPosition(newPosition);
            cout << currentPlayer->getName() << " rolled a " << diceRoll << " and moved to position " << newPosition << endl;

            if (newPosition == board->getSize())
            {
                cout << currentPlayer->getName() << " wins!" << endl;
                break;
            }
        }
    }
};