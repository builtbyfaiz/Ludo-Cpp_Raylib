#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game
{
  public:
    int turn               = 0;   // Wraps linearly, 1-4
    int currentPlayerIndex = -1;  // The Place of active player in the vector

    int dice = 0;

    int numOfActivePlayers = 0;

    bool isNextTurn = true;
    bool debugMode  = true;  // Developer console, allows cheats and logs, Will be used later

    Board board;
    Player *currentPlayer = nullptr;

    raylib::Window window;
    std::vector<Player> players;

    Game();
    void initPlayers();

    void hideInactivePlayerPawns();

    void advanceTurn();
    void rollDice();

    // Game Loop
    void handleInput();
    void update();
    void render();
};