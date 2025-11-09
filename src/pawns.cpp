#include "pawns.hpp"
#include "ludoCells.hpp"

Pawns::Pawns(LudoCells &cells) { init(cells); }

void Pawns::init(LudoCells &cells)
{
    raylib::Color color;
    for (size_t i = 0; i < 4; i++)
    {
        switch (i) {
        case 1:  color = ::RED    ; break;
        case 2:  color = ::GREEN  ; break;
        case 3:  color = ::BLUE   ; break;
        case 4:  color = ::YELLOW ; break;
        default: color = ::WHITE  ; break; }
        
        for (size_t j = 0; j < 4; i++)
        {
            Pawn newPawn(10,);
        }
    }

    //populate the pawns vector. and the sets.
}
