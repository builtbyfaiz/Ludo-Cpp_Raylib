#pragma once
#include "pawn.hpp"

#include <vector>

// Forward declarations
class Cells;

// A class to specifically manage pawns over a specific cell grid/board
class PawnsManager
{
  private:
    static Cells *cells_;
    static std::vector<Pawn> *pawns_;

    struct Outline
    {
        raylib::Color color;
        float thickness;
    }; // helper class

    static Outline getOutline(Pawn &pawn); // Helper function to obtain outline color and thickness of a pawn
    
  public:
    static void bindToBoard(Cells *cells, std::vector<Pawn> *pawns); // Call this first before using PawnManager
    
    // Functions for Pawns
    static void initPawns();    // Initializes the binded pawns vec
    static void renderPawns();  // Renders and renders with outward outline

    // Functions for a chosen Pawn
    static void movePawn(Pawn &pawn, int amount);
    
    
    // Style Helpers for Pawns
    static void highlightPawnsOfColor(raylib::Color playerColor);  // Used to highlight current player via color
    static void hidePawnsOfColor(raylib::Color playerColor);       // Used to hide inactive player pawn via color
    static void deselectAllPawns();                                // Deselects All Pawns and selects none

    // Style Setters for a chosen Pawn
    static void hidePawn(Pawn &pawn);
    static void unhidePawn(Pawn &pawn);

    static void highlightPawn(Pawn &pawn);
    static void unhighlightPawn(Pawn &pawn);
     
    static void selectPawn(Pawn &pawn);
    static void deselectPawn(Pawn &pawn);
};
