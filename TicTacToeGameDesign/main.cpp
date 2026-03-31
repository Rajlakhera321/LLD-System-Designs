#include "./models/Game.h"
#include "./services/GameService.h"
#include "./enums/Symbol.h"
#include "./repositories/GameRepository.h"
#include "./controller/GameController.h"
#include "./interfaces/IWinningStrategies.h"
#include "./strategies/RowColumnDiagonalStrategy.h"

int main()
{
    Board board(3);

    GameRepository gameRepo;
    GameService gameService(&gameRepo, new RowColumnDiagonalStrategy());

    // ✅ CREATE GAME
    gameService.createGame(board);

    int gameId = 0;

    // ✅ ADD PLAYERS (MANDATORY)
    gameService.addPlayerToGame(gameId, "Alice", Symbol::X);
    gameService.addPlayerToGame(gameId, "Bob", Symbol::O);

    GameController controller(&gameService, gameId);

    controller.startGame();

    return 0;
}