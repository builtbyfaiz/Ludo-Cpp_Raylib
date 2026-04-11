#include "Game.hpp"

// Game has Dice as well as the Board and Players #TODO add Dice, players
void Game::handleInput() {}
void Game::update()
{
    if (isNextTurn)
    {
        advanceTurn();
        rollDice();
    }
}

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
    currentPlayer = &players[0];
}

Game::Game()
{
    initPlayers();

    raylib::Window window(750, 750, "Ludo", FLAG_VSYNC_HINT);
    board.init();
}

Game::~Game() { CloseWindow(); }

int consecutiveSixCount; // Count number of consecutive sixes #TODO implement further down the line.

void Game::advanceTurn()
{
    if (dice != 6)
    {
        turn = (turn % 3) + 1;
        currentPlayer = &players[turn];
    }
}

void Game::rollDice()
{
    dice = GetRandomValue(1, 6);
    std::cout << currentPlayer->name << " has Rolled a " << dice;
}