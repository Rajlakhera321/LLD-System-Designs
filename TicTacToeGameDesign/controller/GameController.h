class GameController
{
private:
    GameService *gameService;
    int gameId; // ✅ store only ID

public:
    GameController(GameService *service, int id)
        : gameService(service), gameId(id) {}

    void startGame()
    {
        while (gameService->getGameStatus(gameId) == GameStatus::INPROGRESS)
        {
            gameService->printBoard(gameId);

            string playerName = gameService->getCurrentPlayerName(gameId);

            cout << playerName << "'s turn\n";

            int row, col;
            cin >> row >> col;

            if (!gameService->makeMoveForPlayer(gameId, row, col))
            {
                cout << "❌ Invalid move! Try again.\n";
            }
        }
    }
};