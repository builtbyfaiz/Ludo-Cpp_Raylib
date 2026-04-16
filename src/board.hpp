#pragma once
#include "Cells.hpp"
#include "Pawn.hpp"

class Board
{
  public:
    Cells cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
                 // handleinput for pawn, handle input for path

    std::vector<Pawn> pawns;

    Board();

    void init();
    void render();
};