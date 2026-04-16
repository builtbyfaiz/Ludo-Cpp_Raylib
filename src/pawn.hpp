#pragma once
#include "Cell.hpp"
#include "raylib-cpp.hpp" // IWYU pragma: keep

class Cell; //Forward-Declaration

class Pawn
{
  private:
    int ID; // Unique identifier to be assigned to each pawn.
    
    // Pawn Base
    float size = 30;

    raylib::Rectangle rect = {0, 0, size, size}; // Default
    raylib::Color color;

    // Pawn Styling
    bool selected    = false; // Based on click
    bool highlighted = false; // Based on turn
    bool hidden      = false; // For Inactive player pawns

  public:
    int score = 0; // Equivalent to total cells travelled, used for checking win condition.

    // Pawn Base State
    bool isSpawned     = false; 
    bool isMoveable    = false; // Based on state
    bool isKillable    = false; // Based on state

    // Pawn's Cell information
    Cell *currentCell = nullptr;
    Cell *homeCell    = nullptr;
    Cell *spawnCell   = nullptr;

    Pawn(Cell *hC);

    // void update();
    void renderWithOutline(raylib::Color outlineColor, float thickness);

    void moveTo(Cell *nextCell);

    void spawn();
    void die();

    // Getter Methods
    const raylib::Rectangle getRect();
    const raylib::Color getColor();
    const int getScore();

    // Setter Methods
    // void setOutline(raylib::Color color, float thickness);
    void setColor(raylib::Color color);

    void hide();
    void unhide();

    void highlight();
    void unhighlight();

    void select();
    void deselect();
    
    bool isSelected()    ;  // Based on click
    bool isHighlighted();   // Based on turn
    bool isHidden();      // For Inactive player pawns
};
