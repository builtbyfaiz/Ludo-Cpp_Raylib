#pragma once
#include "Globals.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

#include <iostream>
#include <string>

class Player
{
  public:
    int turn;            // Players clock-wise turn
    std::string name;    // Player name
    raylib::Color color; // Player-Home color, This must be defined from globals

    Player(std::string name = "Default", int turn = 0, raylib::Color color = LUDO_RED)
        : name(name), turn(turn), color(color)
    {
        if (color == LUDO_BLUE || color == LUDO_RED || color == LUDO_GREEN || color == LUDO_YELLOW)
        {
            this->color = color;
        }
        else
        {
            std::cout << "Invalid Color, Choose a color from globals.hpp";
        }
    }
};
