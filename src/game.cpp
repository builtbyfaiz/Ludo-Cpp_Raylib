#include "Game.hpp"

#include "GameRules.hpp"
#include "Pawn.hpp"
#include "PawnsManager.hpp"

#include <iostream>

// Constructor
Game::Game() : window(raylib::Window(750, 750, "Ludo", FLAG_VSYNC_HINT))
{
    GameRules::bindToGameState(this); // The rules helper will be used to validate moves of this game.

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

void Game::advanceTurnToNextPlayer()
{
    do
    {
        currentPlayerIndex++;
        if (currentPlayerIndex == 4) // Wrap index 0-3 as there are 4 total players
            currentPlayerIndex = 0;
    } while (!players[currentPlayerIndex].isActive);

    currentPlayer = &players[currentPlayerIndex];
    turn = currentPlayer->turnOrder; // Players store their turn order which we use.
    std::cout << "\nPlayer" << turn << " " << players[currentPlayerIndex].name << "\'s turn:\n";
}

void Game::rollDice()
{
    dice = GetRandomValue(1, 6);
    std::cout << currentPlayer->name << " Rolled a " << dice << ", Make your move and Press M\n";
}

// GAME LOOP

// Handles Input and sets intent.
void Game::handleInput()
{
    // if mouse button clicked, proceed else return
    if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    PawnsManager::deselectAllPawns(); // Deselect all pawns if randomly click on cell

    for (auto &pawn : board.pawns)
    {
        if (currentPlayer->color != pawn.getColor())
            continue; // skip if pawn is of a different color than active player

        if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
            continue; // Skip if pawn is not the one clicked

        PawnsManager::selectPawn(pawn); // Select the clicked pawn.
    }
}

void Game::update()
{
    // Temp equivalent to making a move + rolling the dice
    // This works unless we need to allow player to choose what dice to use when 6 is rolled

    if (!IsKeyPressed(KEY_M)) return; //if move key not pressed return

    Pawn* selectedPawn  = PawnsManager::getSelectedPawn();
    bool movesAvailable = GameRules::movesExist();
    bool moveMade       = false;

    if (!movesAvailable)
    {
        std::cout << "No moves available. Skipping turn.\n";
    }
    else if (selectedPawn == nullptr)
    {
        std::cout << "No pawn selected. Click to select.\n";
        return; // Wait for pawn selection.
    }
    else if (GameRules::canSpawn(*selectedPawn))
    {
        PawnsManager::spawnPawn(*selectedPawn);
        moveMade = true;
    }
    else if (GameRules::canMove(*selectedPawn))
    {
        PawnsManager::movePawn(*selectedPawn, dice);
        //checkkill
        moveMade = true;
    }
    else
    {
        std::cout << "Pawn not moveable. Pick a different pawn.\n";
        return; // Wait for a better selection of pawn
    }
    
    if ((dice != 6 && moveMade) || !movesAvailable) // Advance turn if a valid move has been made or no moves available
        advanceTurnToNextPlayer();


    rollDice();
    PawnsManager::deselectAllPawns();
    PawnsManager::highlightPawnsOfColor(currentPlayer->color);
}

// Temp Variables
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

    int textX = round((GetScreenWidth()  - fontSize + 25) / 2.0);
    int textY = round((GetScreenHeight() - fontSize     ) / 2.0);

    BeginDrawing();
    ClearBackground(raylib::BLACK);

    board.render();
    raylib::DrawText(std::to_string(dice), textX, textY, fontSize, WHITE);

    EndDrawing();
}

// int consecutiveSixCount; // Count number of consecutive sixes #TODO implement further down the line.