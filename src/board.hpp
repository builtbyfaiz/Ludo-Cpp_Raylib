#pragma once
#include "ludoCells.hpp"
#include "pawnsManager.hpp"

class Board
{
  private:
    LudoCells
        cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
               // handleinput for pawn, handle input for path

    PawnsManager pawns;

  public:
     Board() : pawns(&cells) {}
    
    void init();
    void render();
};