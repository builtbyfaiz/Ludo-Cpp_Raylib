
#include "PawnsManager.hpp"

#include "Cells.hpp"
#include "Globals.hpp"
#include "PawnMaps.hpp"
#include "pawn.hpp"

raylib::Color prevOutlineColorOfPawn = WHITE;
float prevOutlineCThicknessOfPawn = 0;

// Initialize Static variables for the static class
Cells *PawnsManager::cells_;
std::vector<Pawn> *PawnsManager::pawns_;

// Important, before using pawnsManager, Bind it to pawns to manage and cells to manage over.
void PawnsManager::bindToBoard(Cells *cells, std::vector<Pawn> *pawns)
{
    cells_ = cells;
    pawns_ = pawns;
}

void PawnsManager::initPawns()
{
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
    for (auto &p : *pawns_)
        p.moveTo(p.homeCell);
}

// void PawnsManager::hidePawn(Pawn &pawn) { pawn.setColor({0, 0, 0, 0}); }

void PawnsManager::movePawn(Pawn &pawn, int dice)
{
    if (pawn.isSpawned && pawn.isMoveable && pawn.isSelected())
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
}

void PawnsManager::renderPawns()
{
    for (auto &pawn : *pawns_)
    {
        pawn.renderWithOutline(getOutline(pawn).color, getOutline(pawn).thickness);
    }
}

// Resets highlight and deselects pawns. #TODO better semantic naming
// void PawnsManager::resetHighlightOfPawns()
// {
//     for (auto &p : *pawns_)
//     {
//         p.isSelected = false;
//         p.setOutline(OUTLINE_DEFAULT_COLOR,
//                      OUTLINE_THICKNESS_DEFAULT); // Reset all pawns outline to default
//     }
// }

void PawnsManager::hidePawn(Pawn &pawn) { pawn.hide(); }
void PawnsManager::unhidePawn(Pawn &pawn) { pawn.unhide(); }

void PawnsManager::highlightPawn(Pawn &pawn) { pawn.highlight(); }
void PawnsManager::unhighlightPawn(Pawn &pawn) { pawn.unhighlight(); }

void PawnsManager::selectPawn(Pawn &pawn)
{
    // Deselect all other pawns first as there can only be one selected pawn.
    for (auto &p : *pawns_)
    {
        p.deselect();
    }

    pawn.select();
}

void PawnsManager::deselectPawn(Pawn &pawn) { pawn.deselect(); }

PawnsManager::Outline PawnsManager::getOutline(Pawn &pawn)
{
    float         thickness = OUTLINE_DEFAULT_THICKNESS;
    raylib::Color color     = OUTLINE_DEFAULT_COLOR;

    if (pawn.isHighlighted())
    {
        thickness = OUTLINE_HIGHLIGHT_THICKNESS;
        color     = OUTLINE_COLOR_HIGHLIGHT;
    }

    if (pawn.isSelected())
    {
        thickness = OUTLINE_THICKNESS_SELECTION;
        color     = OUTLINE_COLOR_SELECTION;
    }

    if (pawn.isHidden())
    {
        color = raylib::Color(0, 0, 0, 0);
        thickness = 0.0f;
    }

    return {color, thickness};
}

// Unhighlights other pawns, and highlights the pawns of selected color
void PawnsManager::highlightPawnsOfColor(raylib::Color playerColor)
{
    for (auto &pawn : *pawns_)
    {
        if (pawn.getColor() == playerColor)
            pawn.highlight();
        else
            pawn.unhighlight();
    }
}

void PawnsManager::hidePawnsOfColor(raylib::Color playerColor)
{
    for (auto &pawn : *pawns_)
    {
        if (pawn.getColor() == playerColor)
        {
            pawn.hide();
        }
    }
}

void PawnsManager::deselectAllPawns()
{
    for (auto &pawn : *pawns_)
    {
        pawn.deselect();
    }
}

// void PawnsManager::setOutlineOfPawn(Pawn *pawn, raylib::Color color, float thickness)
// {
//     pawn->setOutline(color, thickness);
// }
