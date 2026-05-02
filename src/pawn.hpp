#pragma once
#include "raylib-cpp.hpp" // IWYU pragma: keep

class Cell; //Forward-Declaration

class Pawn
{
  private:
    int ID; // Unique identifier to be assigned to each pawn.

    // Pawn Base
    const float SIZE = 30;

    raylib::Rectangle rect = {0, 0, SIZE, SIZE}; // Default
    raylib::Color color;

    // Pawn Styling
    bool hidden      = false;  // For Inactive player pawns or won pawns
    bool highlighted = false;  // Based on turn, valid moveable pawns
    bool selected    = false;  // Based on click,

    bool spawned   = false;
    bool onWinPath = false;
    bool won       = false;

  public:
    int score = 0; // Equivalent to total cells travelled, used for checking win condition.

    // Pawn's Cell information
    Cell *homeCell    = nullptr;
    Cell *spawnCell   = nullptr;
    Cell *currentCell = nullptr;

    Pawn(Cell *hC); // Use home cell for initialization

    void moveTo(Cell *nextCell);
    
    void spawn();
    void die();
    
    void renderWithOutline(raylib::Color outlineColor, float thickness);

    // Getter Methods
    const int getScore();
    const raylib::Color getColor();
    const raylib::Rectangle getRect();
    
    // Pawn Base State
    bool isSpawned();
    bool hasWon();
    
    // Outline Style Getters
    bool isHidden();      // For Inactive player pawns
    bool isHighlighted(); // Based on turn
    bool isSelected();    // Based on click
    
    // Setter Methods
    void setColor(raylib::Color color);

    // Outline Style Setters
    void hide();
    void unhide();

    void select();
    void deselect();

    void highlight();
    void unhighlight();
};
