#include <bits/stdc++.h>
#include "./interfaces/IDiceStrategy.h"
#include "./strategies/diceStrategies/NormalDiceStrategy.h"
#include "./models/Board.h"
#include "./models/Player.h"
#include "./GameService.h"

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

    queue<unique_ptr<Player> > players;
    players.push(make_unique<Player>("Alice"));
    players.push(make_unique<Player>("Bob"));

    unique_ptr<IDiceStrategy> diceStrategy = make_unique<NormalDiceStrategy>();
    unique_ptr<IMoveStrategy> moveStrategy = make_unique<NormalMoveStrategy>();
    unique_ptr<IWinningStrategy> winningStrategy = make_unique<ExactWinningStrategy>();

    unique_ptr<IGameObserver> consoleLogger = make_unique<ConsoleLogger>();

    GameService gameService(make_unique<Board>(*board), move(players), move(diceStrategy), move(moveStrategy), move(winningStrategy));

    gameService.addObserver(move(consoleLogger));

    gameService.play();
}