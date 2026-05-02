
#include "PawnsManager.hpp"

#include "Cells.hpp"
#include "Globals.hpp"
#include "PawnMaps.hpp"
#include "pawn.hpp"

// PRIVATE

// Initialize Static variables for the static class
Cells *PawnsManager::cells_;
std::vector<Pawn> *PawnsManager::pawns_;

PawnsManager::Outline PawnsManager::getOutline(Pawn &pawn)
{
    float thickness = OUTLINE_THICKNESS_DEFAULT;
    raylib::Color color = OUTLINE_COLOR_DEFAULT;

    if (pawn.isHighlighted())
    {
        color = OUTLINE_COLOR_HIGHLIGHT;
        thickness = OUTLINE_THICKNESS_HIGHLIGHT;
    }

    if (pawn.isSelected())
    {
        color = OUTLINE_COLOR_SELECTION;
        thickness = OUTLINE_THICKNESS_SELECTION;
    }

    if (pawn.isHidden())
    {
        color = raylib::Color(0, 0, 0, 0);
        thickness = 0.0f;
    }

    return {color, thickness};
}

// PUBLIC

// Important, before using pawnsManager, Bind it to pawns to manage and cells to manage over.
void PawnsManager::bindToBoard(Cells *cells, std::vector<Pawn> *pawns)
{
    cells_ = cells;
    pawns_ = pawns;
}

// Initialize the pawns_ vector with game data from globals
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

// Render pawns with their respective outward outline
void PawnsManager::renderPawns()
{
    for (auto &pawn : *pawns_)
        pawn.renderWithOutline(getOutline(pawn).color, getOutline(pawn).thickness);
}

void PawnsManager::spawnPawn(Pawn &pawn)
{
    if (!pawn.isSelected())
        return;

    pawn.spawn();
}

// Moves a pawn in the path grid according to the dice
void PawnsManager::movePawn(Pawn &pawn, int dice)
{
    // Return if the requested move is not valid, redundant validation for good measure
    if (!pawn.isSpawned())
        return;
    if (!pawn.isSelected())
        return;

    int newPathID = pawn.currentCell->getPathID() + dice;

    const int TOTAL_PATH_CELLS = 52;

    // This is to allow looping around the path
    if (newPathID > TOTAL_PATH_CELLS)
        newPathID -= TOTAL_PATH_CELLS;

    // Find the cell with needed newPathID
    for (int i = 0; i < cells_->GRID_SIZE; i++)
    {
        for (int j = 0; j < cells_->GRID_SIZE; j++)
        {
            if (cells_->grid[i][j].getPathID() == newPathID)
            {
                pawn.moveTo(&cells_->grid[i][j]); // Move to new cell and set that as currentCell
                pawn.score += dice;
                // Add primitive Death mechanism, simple,
                for (auto &storedPawn : pawn.currentCell->pawnsOnCell)
                {
                    if (storedPawn->getColor() != pawn.getColor())
                    {
                        storedPawn->die();
                    }
                }
                return;
            }
        }
    }
}

bool PawnsManager::pawnMatchesColor(Pawn &pawn, raylib::Color color)
{
    return pawn.getColor() == color;
}

Pawn *PawnsManager::getSelectedPawn()
{
    for (auto &pawn : *pawns_)
    {
        if (pawn.isSelected())
            return &pawn;
    }
    return nullptr;
}

void PawnsManager::deselectAllPawns()
{
    for (auto &pawn : *pawns_)
    {
        pawn.deselect();
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