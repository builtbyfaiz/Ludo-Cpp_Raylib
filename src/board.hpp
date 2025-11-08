#pragma once
#include "ludoCells.hpp"

// clang-format off
class Board
{
  private:
    ludoCells cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
                     // handleinput for pawn, handle input for path
  public:
    void update();
    void render();
};