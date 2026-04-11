#pragma once
#include "Globals.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

#include <iostream>
#include <string>

class Player
{
  public:
    int turnOrder;       // Player's clock-wise turn order
    std::string name;    // Player's name
    raylib::Color color; // Player-Home color, This must be defined from globals
    bool isActive = true;

    Player(std::string playerName = "Default", int turn = 0, raylib::Color playerColor = LUDO_RED)
        : name(playerName), turnOrder(turn), color(playerColor)
    {
        if (playerColor == LUDO_BLUE || playerColor == LUDO_RED || playerColor == LUDO_GREEN ||
            playerColor == LUDO_YELLOW)
        {
            this->color = playerColor;
        }
        else
        {
            std::cout << "Invalid Color, Choose a color from Globals.hpp";
        }
    }
};
