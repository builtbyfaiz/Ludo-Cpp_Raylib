#include "pawns.hpp"
#include "ludoCells.hpp"
#include <iostream>

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
    std::cout << allPawns.size();
}

void Pawns::render()
{
    for (auto &pawn : allPawns)
    {
        pawn.render();
    }
}
