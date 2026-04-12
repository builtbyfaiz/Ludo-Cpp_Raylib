#include "PawnsManager.hpp"

#include "Cells.hpp"
#include "PawnMaps.hpp"
#include "pawn.hpp"

// Initialize Static variables
Cells *PawnsManager::cells_;
std::vector<Pawn> *PawnsManager::pawns_;

void PawnsManager::init()
{
    pawns_->reserve(16);
    for (auto &row : cells_->grid)
    {
        for (auto &cell : row)
        {
            if (cell.getHomeID() <= 0) // If iD doesn't exist i.e = 0 skip iteration.
                continue;

            pawns_->emplace_back(&cell); // Generate new pawn on Home-cell
            Pawn &pawn = pawns_->back(); // Set a reference to the new pawn

            pawns_->back().spawnCell = &cells_->grid[ColorToPawnSpawnPos(pawn.getColor()).y]
                                                    [ColorToPawnSpawnPos(pawn.getColor()).x];
        }
    }
    for (auto& p : *pawns_)
        p.moveTo(p.homeCell);
}

void PawnsManager::movePawn(Pawn &pawn, int dice)
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

void PawnsManager::renderPawns()
{
    for (auto &pawn : *pawns_)
    {
        pawn.render();
    }
}

void PawnsManager::selectPawn(Pawn &pawn)
{
    for (auto &p : *pawns_)
    {
        p.isSelected = false;
        p.setOutline(BLACK, 1); // Reset all pawns outline to default
    }

    pawn.isSelected = true;
    pawn.setOutline(PURPLE, 2); // Highlight selected pawn.
}

// Important, before using pawnsManager, Bind it to pawns to manage and cells to manage over.
void PawnsManager::bindToBoard(Cells *cells, std::vector<Pawn> *pawns)
{
    cells_ = cells;
    pawns_ = pawns;
}
