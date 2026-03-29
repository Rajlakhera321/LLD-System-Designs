#include "./models/Game.h"
#include "./services/GameService.h"
#include "./enums/Symbol.h"
#include "./repositories/GameRepository.h"
#include "./controller/GameController.h"
#include "./interfaces/IWinningStrategies.h"
#include "./strategies/RowColumnDiagonalStrategy.h"

int main()
{
    Game game(3);

    game.addPlayer("Alice", Symbol::X);
    game.addPlayer("Bob", Symbol::O);

    GameRepository gameRepo;

    GameService gameService(&gameRepo, new SimpleWinningStrategy());

    GameController controller(&gameService, game);

    gameRepo.addGame(game);

    controller.startGame();
    return 0;
}