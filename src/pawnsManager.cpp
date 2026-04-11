#include "PawnsManager.hpp"

#include "Cells.hpp"
#include "PawnMaps.hpp"

void PawnsManager::init()
{
    for (auto &row : cells_->grid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() <= 0) // If iD doesn't exist i.e = 0 skip iteration.
                continue;

            allPawns.emplace_back(&cell); // Generate new pawn on Home-cell
            Pawn &pawn = allPawns.back(); // Set a reference to the new pawn

            allPawns.back().spawnCell = &cells_->grid[ColorToPawnSpawnPos(pawn.getColor()).y]
                                                     [ColorToPawnSpawnPos(pawn.getColor()).x];
        }
    }
}

void PawnsManager::move(Pawn &pawn, int dice)
{
    int newPathID = pawn.currentCell->getPathID() + dice;
    if (newPathID > 52)
        newPathID -= 52;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (cells_->grid[i][j].getPathID() == newPathID)
            {
                pawn.moveTo(&cells_->grid[i][j]);
                pawn.score += dice;
                return;
            }
        }
    }
}

void PawnsManager::render()
{
    for (auto &pawn : allPawns)
    {
        pawn.render();
    }
}

void PawnsManager::selectPawn(Pawn &pawn)
{
    for (auto &p : allPawns)
    {
        p.isSelected = false;
        p.setOutline(BLACK, 1); // Reset all pawns outline to default
    }
    
    pawn.isSelected = true;
    pawn.setOutline(PURPLE, 2); // Highlight selected pawn.
}
