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
    int   turn = 1;
    int   dice = 0; 


  public:
    Board() {};

    void handleClick();
    void rollDice();
    bool isPawnValid(Pawn pawn);
    
    void init();
    void handleInput();
    void update();
    void render();
};