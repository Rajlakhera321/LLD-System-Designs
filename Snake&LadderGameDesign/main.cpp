#include <bits/stdc++.h>
#include "./interfaces/IDiceStrategy.h"
#include "./strategies/diceStrategies/NormalDiceStrategy.h"
#include "./strategies/moveStrategies/NormalMoveStrategy.h"
#include "./strategies/winningStrategies/ExactWinningStrategy.h"
#include "./factories/DiceFactory.h"
#include "./factories/MoveFactory.h"
#include "./factories/WinningFactory.h"
#include "./observers/ConsoleLogger.h"
#include "./models/Board.h"
#include "./models/Player.h"
#include "./GameService.h"

using namespace std;

int main()
{
    auto board = make_unique<Board>(100);

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

    unique_ptr<DiceFactory> diceFactory = make_unique<DiceFactory>();
    unique_ptr<MoveFactory> moveFactory = make_unique<MoveFactory>();
    unique_ptr<WinningFactory> winningFactory = make_unique<WinningFactory>();

    unique_ptr<IDiceStrategy> diceStrategy = diceFactory->createDiceFactory("Normal");
    unique_ptr<IMoveStrategy> moveStrategy = moveFactory->createMoveStrategy("Normal");
    unique_ptr<IWinningStrategy> winningStrategy = winningFactory->createWinningStrategy("Exact");

    unique_ptr<IGameObserver> consoleLogger = make_unique<ConsoleLogger>();

    GameService gameService(move(board), move(players), move(diceStrategy), move(moveStrategy), move(winningStrategy));

    gameService.addObserver(move(consoleLogger));

    gameService.play();
}