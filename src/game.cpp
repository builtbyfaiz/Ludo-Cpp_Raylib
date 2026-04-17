#include "Game.hpp"

#include "Pawn.hpp"
#include "PawnsManager.hpp"

#include <iostream>

// Constructor
Game::Game() : window(raylib::Window(750, 750, "Ludo", FLAG_VSYNC_HINT))
{
    initPlayers();
    board.init(); // Initiate full cell board and the 16 pawns
    hideInactivePlayerPawns();
}

void Game::initPlayers()
{
    // Initialize All default Players, and then deactivate unused players
    players.emplace_back(Player("Player1", 1, LUDO_RED));
    players.emplace_back(Player("Player2", 2, LUDO_GREEN));
    players.emplace_back(Player("PLayer3", 3, LUDO_YELLOW));
    players.emplace_back(Player("Player4", 4, LUDO_BLUE));

    // Ask for players actively playing, and exit loop when valid input
    do
    {
        std::cout << "Enter Number of Active Players(2-4): ";
        std::cin >> numOfActivePlayers;
    } while (numOfActivePlayers != 4 && numOfActivePlayers != 3 && numOfActivePlayers != 2);

    // Mark Diagonal players active if 2 are active.
    if (numOfActivePlayers == 2)
    {
        players[1].isActive = false;
        players[3].isActive = false;

        players[2].turnOrder = 2; // Mark Yellow i.e 3rd in vector as player2
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
        if (!player.isActive)
        {
            PawnsManager::hidePawnsOfColor(player.color);
        }
    }
}

void Game::advanceTurn()
{
    if (dice != 6 && isValidMovePlayed) // If the dice was previosly 6, turn won't advance
    {
        do
        {
            currentPlayerIndex++;
            if (currentPlayerIndex == 4) // Wrap index 0-3 as there are 4 total players
                currentPlayerIndex = 0;
        } while (!players[currentPlayerIndex].isActive);
    }

    currentPlayer = &players[currentPlayerIndex];
    turn = currentPlayer->turnOrder; // Players store their turn order which we use.
    std::cout << "\nPlayer" << turn << " " << players[currentPlayerIndex].name << "\'s turn:\n";
}

void Game::rollDice()
{
    dice = GetRandomValue(1, 6);
    std::cout << currentPlayer->name << " Rolled a " << dice << ", Make your move and Press R\n";
}

// GAME LOOP

// Handles Input and sets intent.
void Game::handleInput()
{
    // if mouse button clicked, proceed else return
    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    PawnsManager::deselectAllPawns(); // This is done so that clicking on a cell deselects all

    for (auto &pawn : board.pawns)
    {
        if (currentPlayer->color == pawn.getColor())
        {
            if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
                continue; // Skip iteration if current pawn is not the one clicked

            PawnsManager::selectPawn(pawn); // Select the clicked pawn.
        }
        // Make your move here, allowed to ask player ;p
    }
}

void Game::update()
{
    // Temp equivalent to making a move + rolling the dice
    // This works unless we need to allow player to choose what dice to use when 6 is rolled

    if (IsKeyPressed(KEY_M)) // Use M to move
    {
        for (auto &pawn : board.pawns)
        {
            if (!(pawn.getColor() == currentPlayer->color && pawn.isSelected()))
                continue; // Skip iteration if pawn is not selected and not current players

            if (pawn.isSpawned())
            {
                PawnsManager::movePawn(pawn, dice);
                isValidMovePlayed = true;
            }
            else if (!pawn.isSpawned() && dice == 6)
            {
                pawn.spawn();
                isValidMovePlayed = true;
            }
            else
            {
                std::cout << "Invalid Move Played, Try again and Press R\n";
                isValidMovePlayed = false;
            }
        }
    }

    if (isValidMovePlayed)
    {
        isNextTurn = 1;
        isValidMovePlayed = false;
    }

    if (isNextTurn)
    {
        advanceTurn();
        rollDice();

        PawnsManager::deselectAllPawns();
        PawnsManager::highlightPawnsOfColor(currentPlayer->color);

        isNextTurn = false;
    }
}

// Temp Variables
int textX;
int textY;
int iterator = 0;
void Game::render()
{
    // Display current value of dice in center
    raylib::Rectangle rect = board.cells.grid[7][7].getRect();

    int fontSize = (rect.height / 1) + iterator;
    if (IsKeyPressed(KEY_L))
    {
        iterator++;
        std::cout << fontSize;
    }
    if (IsKeyPressed(KEY_K))
    {
        iterator--;
        std::cout << fontSize;
    }

    textX = (GetScreenWidth() - fontSize + 25) / 2;
    textY = (GetScreenHeight() - fontSize) / 2;

    BeginDrawing();
    ClearBackground(raylib::BLACK);

    board.render();
    raylib::DrawText(std::to_string(dice), textX, textY, fontSize, WHITE);

    EndDrawing();
}

// int consecutiveSixCount; // Count number of consecutive sixes #TODO implement further down the line.