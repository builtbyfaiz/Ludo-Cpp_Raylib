#include "pawns.hpp"

#include "ludoCells.hpp"
#include "mappingsPawns.hpp"

void Pawns::init()
{
    for (auto &row : cells_->cellsGrid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() <= 0) // If iD doesn't exist i.e = 0 skip iteration.
                continue;

            allPawns.emplace_back(&cell); // Generate new pawn
            Pawn &pawn = allPawns.back(); // Set a reference to the new pawn

            allPawns.back().spawnCell = &cells_->cellsGrid[colorSpawnMap(pawn.getColor()).y]
                                                          [colorSpawnMap(pawn.getColor()).x];
        }
    }
}

void Pawns::move(Pawn &pawn, int dice)
{
    int newPathID = pawn.currentCell->getPathID() + dice;
    if (newPathID > 52)
        newPathID -= 52;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (cells_->cellsGrid[i][j].getPathID() == newPathID)
            {
                pawn.moveTo(&cells_->cellsGrid[i][j]);
                pawn.score += dice;
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

void Pawns::handleInput() {}