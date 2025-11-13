#include "pawns.hpp"
#include "ludoCells.hpp"
#include "mappingsPawns.hpp"
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
                Pawn newPawn(&cell); // Assign Home Cell
                newPawn.spawnCell =
                    &cells->cellsGrid[colorSpawnMap[newPawn.getColor()].y]
                                     [colorSpawnMap[newPawn.getColor()].x];
                allPawns.push_back(newPawn);
            }
        }
    }
    assignSpawnCells(cells);
}

void Pawns::render()
{
    for (auto &pawn : allPawns)
    {
        pawn.render();
    }
}

void Pawns::handleInput() 
{
    
}