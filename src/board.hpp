#pragma once
#include "ludoCells.hpp"
#include "pawns.hpp"
// clang-format on
class Board
{
  private:
    LudoCells
        cells; // #TODO Dice, Pawns.. dice.hpp, pawn.hpp, handleinput for dice,
               // handleinput for pawn, handle input for path
    Pawns pawns;
  
    
  public:
    Board() {};

    void init();
    void handleInput();
    void update();
    void render();
};