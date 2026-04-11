#pragma once
#include "Cells.hpp"
#include "PawnsManager.hpp"

class Board
{
  private:
    int dice = 0;
    Cells cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
                 // handleinput for pawn, handle input for path

    PawnsManager pawns;

  public:
     Board() : pawns(&cells) {}
    
    void init();
    void render();
};