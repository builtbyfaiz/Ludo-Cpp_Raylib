#pragma once
#include "ludoCells.hpp"

// clang-format on
class Board
{
  private:
    LudoCells
        cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
               // handleinput for pawn, handle input for path
  public:
    void init();
    void update();
    void render();
};