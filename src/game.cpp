#include "Game.hpp"

// Game has Dice as well as the Board and Players #TODO add Dice, players
void Game::handleInput() 
{

}
void Game::update() {}

void Game::render()
{
    BeginDrawing();
    ClearBackground(raylib::BLACK);

    board.render();

    EndDrawing();
}

void Game::initPlayers()
{
    int numOfPlayers = 0;

    // Initialize All default Players, and then deactivate unused players
    players.emplace_back(Player("Player1", 1, LUDO_RED));
    players.emplace_back(Player("Player2", 2, LUDO_GREEN));
    players.emplace_back(Player("PLayer3", 3, LUDO_YELLOW));
    players.emplace_back(Player("Player4", 4, LUDO_BLUE));

    do
    {
        std::cout << "Enter Number of Active Players(2-4): ";
        std::cin >> numOfPlayers;
    } while (numOfPlayers != 4 && numOfPlayers != 3 && numOfPlayers != 2);

    if (numOfPlayers == 2)
    {
        players[1].isActive = false;
        players[3].isActive = false;
        players[2].turnOrder = 2; // Mark Yellow as player2
    }

    if (numOfPlayers == 3)
        players[3].isActive = false;

    for (auto &player : players)
    {
        if (player.isActive)
        {
            std::cout << "Enter player" << player.turnOrder << "\'s name: ";
            std::cin >> player.name;
        }
    }
}

Game::Game()
{
    initPlayers();

    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(750, 750, "Ludo");
    board.init();
}

Game::~Game() { CloseWindow(); }
