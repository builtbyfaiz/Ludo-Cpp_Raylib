#pragma once
#include "pawn.hpp"

#include <vector>

// Forward declarations
class Cells;

// A class made to specifically manage pawns over a specific cell grid/board
class PawnsManager
{
  private:
    static Cells *cells_;
    static std::vector<Pawn> *pawns_;

  public:
    struct Outline
    {
        raylib::Color color;
        float thickness;
    }; // helper class

    static void bindToBoard(Cells *cells, std::vector<Pawn> *pawns);
    static void initPawns();

    static void renderPawns();
    static void movePawn(Pawn &pawn, int amount);
    
    static Outline getOutline(Pawn &pawn);

    static void highlightPawnsOfColor(raylib::Color playerColor);  // Used to highlight current player via color
    static void hidePawnsOfColor(raylib::Color playerColor);       // Used to hide inactive player pawn via color
    static void deselectAllPawns();                                // Deselects All Pawns and selects none

    // Style Setters
    static void hidePawn(Pawn &pawn);
    static void unhidePawn(Pawn &pawn);

    static void selectPawn(Pawn &pawn);
    static void deselectPawn(Pawn &pawn);

    static void highlightPawn(Pawn &pawn);
    static void unhighlightPawn(Pawn &pawn);
};
