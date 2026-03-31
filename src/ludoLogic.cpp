#include "ludoLogic.h"
#include "pawn.hpp"
#include "raylib-cpp.hpp"

// Matches Color to turn in a clockwise 1-4 fashion, Returns true if pawn is turn's color
bool LudoLogic::isValidOnTurn(Pawn pawn, int turn)
{
    switch (turn) // clang-format off
    {
    case 1: if (pawn.getColor() == LUDO_RED   ) return true; else return false;
    case 2: if (pawn.getColor() == LUDO_GREEN ) return true; else return false;
    case 3: if (pawn.getColor() == LUDO_YELLOW) return true; else return false;
    case 4: if (pawn.getColor() == LUDO_BLUE  ) return true; else return false;
    
    default: return false;
    } // clang-format on
}