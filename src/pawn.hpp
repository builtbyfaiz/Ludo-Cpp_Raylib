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
    raylib::Rectangle rect = {0, 0, 0, 0};

  public:
    enum class State
    {
        IN_HOME,
        MOVEABLE,
        FROZEN,
        WON
    } state = State::IN_HOME;

    LudoCell *currentCell;
    LudoCell *homeCell;
    LudoCell *spawnCell;

    Pawn(int x = 0, int y = 0, raylib::Color c = ::WHITE,
         LudoCell *cc = nullptr)
        : rect(x, y, size, size), color(c), currentCell(cc), homeCell(cc)
    {
    }
    void update();
    void render();
    void returnHome();               //Aka die
    void exitHome();                 //Aka be Born
    void moveTo(LudoCell *nextCell); //Aka Keep moving Forward #eren
};