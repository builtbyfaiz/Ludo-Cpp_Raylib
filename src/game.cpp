#include "Game.hpp"

#include "PawnsManager.hpp"
#include "pawn.hpp"

#include <iostream>

// Game has Dice as well as the Board and Players #TODO add Dice, players

// Handles Input and sets intent.
void Game::handleInput()
{
    // Check if current player's pawn is clicked then select it.
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        for (auto &pawn : board.pawns)
        {
            if (currentPlayer->color == pawn.getColor())
            {
                if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
                    continue; // Skip iteration if current pawn is not the one clicked

                std::cout << currentPlayer->color.ToString();
                PawnsManager::selectPawn(pawn);
            }
            // Make your move here, allowed to ask player ;p
        }
    }
}

void Game::update()
{

    if (IsKeyPressed(KEY_R))
        isNextTurn = 1;

    if (isNextTurn)
    {
        advanceTurn();
        rollDice();
        for (auto &pawn : board.pawns)
        {
            if (pawn.isSelected && pawn.getColor() == currentPlayer->color)
               PawnsManager::movePawn(pawn, dice);
        }
        std::cout << "\nSelect pawn, and Press R to make move.\n";
        isNextTurn = false;
    }
    // isNextTurn = true? // action happened, it made this? but what?
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
    // Initialize All default Players, and then deactivate unused players
    players.emplace_back(Player("Player1", 1, LUDO_RED));
    players.emplace_back(Player("Player2", 2, LUDO_GREEN));
    players.emplace_back(Player("PLayer3", 3, LUDO_YELLOW));
    players.emplace_back(Player("Player4", 4, LUDO_BLUE));

    do
    {
        std::cout << "Enter Number of Active Players(2-4): ";
        std::cin >> numOfActivePlayers;
    } while (numOfActivePlayers != 4 && numOfActivePlayers != 3 && numOfActivePlayers != 2);

    if (numOfActivePlayers == 2)
    {
        players[1].isActive = false;
        players[3].isActive = false;

        players[2].turnOrder = 2; // Mark Yellow as player2
    }

    if (numOfActivePlayers == 3)
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

void Game::hideInactivePlayerPawns()
{
    for (auto &player : players)
    {
        for (auto &pawn : board.pawns)
        {
            if (!player.isActive && pawn.getColor() == player.color)
            {
                PawnsManager::hidePawn(pawn);
            }
        }
    }
}

Game::Game() : window(raylib::Window(750, 750, "Ludo", FLAG_VSYNC_HINT))
{
    initPlayers();
    board.init(); // Initiate full cells board and the 16 pawns
    hideInactivePlayerPawns();
}

int consecutiveSixCount; // Count number of consecutive sixes #TODO implement further down the line.
int currentPlayerIndex = 0;

void Game::advanceTurn()
{
    if (dice != 6)
    {
        do
        {
            currentPlayerIndex++;
            if (currentPlayerIndex == 4) // Wrap index 0-3 as there are 4 total players
                currentPlayerIndex = 0;
        } while (!players[currentPlayerIndex].isActive);

        currentPlayer = &players[currentPlayerIndex];

        turn = currentPlayer->turnOrder; // Players store their turn order which we use.

        std::cout << "\nTurn of Player" << turn << "\n";
    }
}

void Game::rollDice()
{
    dice = GetRandomValue(1, 6);
    std::cout << currentPlayer->name << " Rolled " << dice << ", Make your move and Press R\n";
}