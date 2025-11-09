#pragma once
#include "raylib-cpp.hpp"
#include "ludoCell.hpp"

class LudoCell; //Forward-Declaration

class Pawn
{
  private:
    int ID;
    
    int size = 15;
    raylib::Color color;
    raylib::Rectangle rect = {0, 0, 0, 0};
    
    public:
    enum class State
    {
        IN_HOME,
        ON_PATH,
        AT_WIN
    } state = State::IN_HOME;
    
    LudoCell &currentCell;
    Pawn(int x, int y, raylib::Color c, LudoCell &cc)
        : rect(x, y, size, size), color(c), currentCell(cc)
    {
    }

    void render();
    void moveTo(LudoCell &nextCell);
};