#pragma once
#include "Board.hpp"
#include "Player.hpp"

class Game {
  public:
    int turn = 0; 
    int dice = 0;
    int numOfActivePlayers = 0;
    
    bool isNextTurn = true;
    bool debugMode = true; // Developer console, allows cheats and logs, Will be used later

    Board board;
    Player* currentPlayer = nullptr;

    std::vector<Player> players;

    raylib::Window window;

    Game();

    void hideInactivePlayerPawns();

    void initPlayers();
    
    void advanceTurn();
    void rollDice();

    void handleInput();
    void update();
    void render();
};

// bool  isNextTurn = false;

// void Board::handleClick()
// {
//     for (auto &pawn : pawns.allPawns)
//     {

//         if (!CheckCollisionPointRec(GetMousePosition(), pawn.getRect()))
//             continue;

//         if (pawn.isValidOnTurn(turn))
//         {
//             if (!pawn.isSpawned && dice == 6)
//             {
//                 pawn.spawn();
//             }
//             else if (pawn.isSpawned && pawn.isMoveable)
//             {
//                 pawns.move(pawn, dice);
//                 std::cout << " Pawn Moved " << "\n";
//             }

//             if (dice != 6)
//             {
//                 turn++;
//                 turn = (turn % 4);
//             }

//             // std::cout << "Dice:" << dice << "\n";
//             // std::cout << "Turn: " << turn << "\n";
//         }
//     }
// }




// void Board::rollDiceSmart()
// {
//     // char keyboardInput;
    
//     std::cout << "\nPlayer" << turn << " enter 'r' to roll dice: ";

//     if (!IsKeyPressed(KeyboardKey::KEY_R))
//     {
//         std::cout << std::endl << "Wrong Input" << std::endl;
        
//     }

//     if (isNextTurn)
//     {
//         dice = GetRandomValue(1, 6);
//         std::cout << "\nPlayer" << turn << " Rolled a " << dice;
//     }
// }

// void Board::handleInput()
// {
//     // Roll Dice on click
//     // Click Pawn (if Pawn == Own Color)
//     // Move Accordingly
//     // Roll Dice Again

//     if (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
//         return;

//     handleClick();
// }


    // for (auto &pawn : pawns.allPawns)
    // {
    //     if (pawn.isValidOnTurn(turn))
    //     {
    //         pawn.isMoveable = true;
    //         pawn.isKillable = false;
    //     }
    //     else
    //     {
    //         pawn.isMoveable = false;
    //         pawn.isKillable = true;
    //     }
    // }
    // rollDiceSmart();

    // for (auto &row : cells.grid) // Check Kills
    // {
    //     for (auto &cell : row)
    //     {
    //     }
    // }