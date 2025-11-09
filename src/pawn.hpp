#pragma once
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"

class LudoCell; //Forward-Declaration

class Pawn
{
  private:
    int ID;
    int distance = 0;
    bool moveable = false;

    float size = 30;
    raylib::Color color;
    raylib::Rectangle rect = {10, 10, size, size}; // Default

  public:
    enum class State
    {
        IN_HOME,
        MOVEABLE,
        FROZEN,
        WON
    } state = State::IN_HOME;

    LudoCell *currentCell = nullptr;
    LudoCell *homeCell;

    // Easter Egg Left By Faiz
    Pawn ( LudoCell *hC );

    void update();
    void render();
    
    void returnHome();               //Aka die
    void moveTo(LudoCell *nextCell); //Aka Keep moving Forward #eren
};