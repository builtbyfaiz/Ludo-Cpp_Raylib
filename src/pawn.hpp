#pragma once
#include "ludoCell.hpp"
#include "raylib-cpp.hpp"

class LudoCell; //Forward-Declaration

class Pawn
{
  private:
    int ID; // Unique identifier to be assigned to each pawn.

    // Pawn Base
    float size = 30;
    raylib::Rectangle rect = {0, 0, size, size}; // Default
    raylib::Color color;

  public:
    int score = 0;

    // Pawn State
    bool isMoveable = false;
    bool isSpawned = false;
    bool isKillable = false;

    // Pawn's Cell information
    LudoCell *currentCell = nullptr;
    LudoCell *homeCell = nullptr;
    LudoCell *spawnCell = nullptr;

    Pawn(LudoCell *hC);

    void update();
    void render();

    bool isValidOnTurn(int turn);

    void moveTo(LudoCell *nextCell);
    void spawn();
    void die();

    // Getter Methods
    const raylib::Rectangle getRect();
    const raylib::Color getColor();
    const bool getState();
    const int getScore();
};