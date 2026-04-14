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
    static void initPawns();
    static void renderPawns();
    
    static void movePawn(Pawn &pawn, int amount);
    static void hidePawn(Pawn &pawn);
    static void selectPawn(Pawn &pawn);

    static void bindToBoard(Cells *cells, std::vector<Pawn> *pawns);
};
