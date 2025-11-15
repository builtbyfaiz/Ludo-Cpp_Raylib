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
    bool  isNextTurn = false;
    int   turn       = 1;
    int   dice       = 0;


  public:
     Board() : pawns(&cells) {}
    void handleClick();
    void rollDice();
    
    void init();
    void handleInput();
    void update();
    void render();
};