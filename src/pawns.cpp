#include "pawns.hpp"
#include "ludoCells.hpp"

void Pawns::init(LudoCells *cells)
{
    raylib::Color color;

    for (auto &row : cells->cellsGrid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() > 0)
            {
                Pawn newPawn(&cell);
                allPawns.push_back(newPawn);
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
