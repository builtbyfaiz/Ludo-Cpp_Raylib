#include "pawns.hpp"
#include "ludoCells.hpp"

Pawns::Pawns(LudoCells *cells) { init(cells); }

void Pawns::init(LudoCells *cells)
{
    raylib::Color color;
    LudoCell *currentCell;
    // clang-format off
    for (size_t i = 0; i < 4; i++)
    {
        switch (i) {
        case 1:  color = ::RED    ; break;
        case 2:  color = ::GREEN  ; break;
        case 3:  color = ::BLUE   ; break;
        case 4:  color = ::YELLOW ; break;
        default: color = ::WHITE  ; break; }

        // clang-format on
        for (auto &row : cells->cellsGrid)
        {
            for (auto &cell : row)
            {
                if (cell.getHomeID() > 0 && cell.getColor() == color)
                {
                    Pawn newPawn(&cell);
                    allPawns.push_back(newPawn);
                }
            }
        }
    }
}

void Pawns::render()
{
    for (auto &pawn : allPawns)
    {
        pawn.render();
    }
}
