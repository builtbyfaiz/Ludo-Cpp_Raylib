#pragma once
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"

class LudoCell; //Forward-Declaration

class Pawn
{
  private:
    int ID;
    int score = 0;
    bool moveable = false;

    int size = 15;
    raylib::Color color;
    raylib::Rectangle rect = {10, 10, 10, 10};

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
    LudoCell *spawnCell;

    // Easter Egg Left By Faiz
    Pawn( LudoCell *hC );

    void update();
    void render();
    
    void returnHome();               //Aka die
    void exitHome();                 //Aka be Born
    void moveTo(LudoCell *nextCell); //Aka Keep moving Forward #eren
};