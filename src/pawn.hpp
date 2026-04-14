#pragma once
#include "Cell.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

class Cell; //Forward-Declaration

class Pawn
{
  private:
    int ID; // Unique identifier to be assigned to each pawn.
    struct Outline
    {
        raylib::Color color = BLACK;
        float thickness = 2;
    } outline;

    // Pawn Base
    float size = 30;

    raylib::Rectangle rect = {0, 0, size, size}; // Default
    raylib::Color color;

  public:
    int score = 0; // Equivalent to total cells travelled, used for checking win condition.

    // Pawn State
    bool isSpawned = false;
    bool isMoveable = false;
    bool isKillable = false;
    bool isSelected = false;

    // Pawn's Cell information
    Cell *currentCell = nullptr;
    Cell *homeCell = nullptr;
    Cell *spawnCell = nullptr;

    Pawn(Cell *hC);

    void update();
    void render();

    void moveTo(Cell *nextCell);

    void spawn();
    void die();

    // Getter Methods
    const raylib::Rectangle getRect();
    const raylib::Color getColor();
    const int getScore();

    // Setter Methods
    void setOutline(raylib::Color color, float thickness);
    void setColor(raylib::Color color);
};