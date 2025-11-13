#include "pawns.hpp"
#include "ludoCells.hpp"
#include "mappingsPawns.hpp"
#include <iostream>

void Pawns::init(LudoCells *cells)
{
    raylib::Color color;
    this->cells = cells;
    for (auto &row : cells->cellsGrid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() > 0)
            {
                Pawn newPawn(&cell); // Assign Home Cell
                newPawn.spawnCell =
                    &cells->cellsGrid[colorSpawnMap(newPawn.getColor()).y]
                                     [colorSpawnMap(newPawn.getColor()).x];
                allPawns.push_back(newPawn);
            }
        }
    }
}

void Pawns::move(Pawn pawn, int amount) 
{
    
    int newPathID = pawn.currentCell->getPathID() + amount;
    for (int i=0;i<15;i++)
    {
        for (int j=0;j<15;j++)
        {
            if(cells->cellsGrid[i][j].getPathID()==newPathID) 
            {
                pawn.moveTo(&cells->cellsGrid[i][j]);
                return;
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

void Pawns::handleInput() 
{

}