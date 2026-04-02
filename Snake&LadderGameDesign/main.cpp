#include <bits/stdc++.h>
#include "./Game.h"
#include "interfaces/IDiceStrategy.h"
#include "strategies/NormalDiceStrategy.h"
#include "./models/Board.h"
#include "./models/Player.h"

using namespace std;

int main()
{
    Board *board = new Board(100); // Create a board of size 100

    board->addJump(3, 22);
    board->addJump(5, 8);
    board->addJump(11, 26);
    board->addJump(20, 29);
    board->addJump(17, 4);
    board->addJump(19, 7);
    board->addJump(27, 1);

    IDiceStrategy *diceStrategy = new NormalDiceStrategy(); // Use a normal dice strategy

    queue<Player *> players;
    players.push(new Player(1, "Alice")); // Add player Alice
    players.push(new Player(2, "Bob"));   // Add player Bob

    Game game(board, players, diceStrategy);
    game.play();
}